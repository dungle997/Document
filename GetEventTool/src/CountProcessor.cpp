#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "CountEvent.hpp"
#include "CountProcessor.hpp"
#include <fstream>
#include <ctime>
#include <string>
CountProcessor::CountProcessor(const std::string& ipcamera, const std::string& username, const std::string& userpwd) : GetImageEngine(){
    this->ipcamera = ipcamera;
    this->username = username;
    this->userpwd = userpwd;
    this->access_token = GetImageEngine::get_Token(this->ipcamera, this->username, this->userpwd);
    this->dirLastEventID = "../Data_EventId/" + this->ipcamera + "/personcount.txt";
    this->dirSaveJson = "../Json_Event/" + this->ipcamera + "/personcount.txt";
    this->lastID = this->loadLastID(this->dirLastEventID); 
    this->urlJson = "https://" + this->ipcamera + ":4004/api/event/persondetection?lastId="+ std::to_string(this->lastID) + "&access_token=" + this->access_token;
    this->urlFrame = "https://"+ this->ipcamera + ":4004/api/event/frame/persondetection/";
}
CountProcessor::~CountProcessor(){
    
}
void CountProcessor::process() {
    std::cout << "Get Count Event" << std::endl;
    std::cout << "ipcamera = " << this->ipcamera << std::endl;
    HttpSession* jsonSession = new HttpSession();
    jsonSession->setUrl(this->urlJson);
    jsonSession->addHeader("Content-Type: application/json");
    jsonSession->start();
    try {
        std::string message((const char *)jsonSession->getData(), jsonSession->getSize());
        handleRequest(message);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Process Events Successfull" << std::endl;
    delete jsonSession;
}
void CountProcessor::handleRequest(std::string& message){
    auto j = json::parse(message);
    std::cout << "path = " << this->dirSaveJson << std::endl;
    std::string Time = CountProcessor::getTime();
    this->saveJson(this->dirSaveJson, message, Time);
    if (message != "[]"){
        std::cout << "j.size() = " << j.size() << std::endl;
        for (int i = j.size() - 1; i > -1; i--) {
            std::vector<cv::Rect> boxes;
            auto jlocations = j[i]["extras"]["objects"];
            for (auto jlocations1 : jlocations){
                auto p1 = jlocations1["locations"];
                cv::Rect box(p1[0], p1[1], p1[2], p1[3]);
                boxes.push_back(box);
            }  
            int EventId = j[i]["eventId"];
            std::cout <<" eventId = " << j[i]["eventId"] << std::endl;
            std::string eventId = j[i]["image_id"];
            std::cout << "imageID = "<<eventId << std::endl;
            std::string time = j[i]["time"];
            std::cout << "--------CountEvent-------" << std::endl;
            CountEvent* newEvent = new CountEvent( boxes, time, eventId, EventId, this->ipcamera);
            std::string currentFrameUrl = urlFrame + eventId + "?access_token=" + this->access_token;
            HttpSession* imageSession = new HttpSession();
            imageSession->addHeader("Content-Type: image/jpeg");
            imageSession->setUrl(currentFrameUrl);
            imageSession->start();
            try {
                std::string dataImage((const char *)imageSession->getData(), imageSession->getSize());
                std::vector<uchar> uImage(dataImage.begin(), dataImage.end());
                cv::Mat image = cv::imdecode(uImage, cv::IMREAD_COLOR);
                newEvent->update(image);
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
            delete imageSession;
            delete newEvent;
        }
        std::cout << "lastId new = "<< j[0]["eventId"] << std::endl;
        int id = j[0]["eventId"];
        this->overrideLastID(this->dirLastEventID, id);
    }   
}

