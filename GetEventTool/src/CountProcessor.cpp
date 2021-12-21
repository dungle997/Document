#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "CountEvent.hpp"
#include "CountProcessor.hpp"
#include <fstream>
#include <ctime>
#include <string>
CountProcessor::CountProcessor() : GetImageEngine(){

}
CountProcessor::~CountProcessor(){
    
}
void CountProcessor::process(const std::string& ipcamera, const std::string& username, const std::string& userpwd) {
    std::cout << "Get Count Event" << std::endl;
    this->access_token = GetImageEngine::get_Token(ipcamera, username, userpwd);
    std::cout << "ipcamera = " << ipcamera << std::endl;
    int lastId = 1;
    std::ifstream file1;
        file1.open("../Data_EventId/" + ipcamera + "/personcount.txt", std::ios::in);
        if(file1.is_open()){
                // std::cout << "line = " << line << std::endl;
                file1 >> lastId;
        }
        std::cout << "lastId = " << lastId <<std::endl; 
        file1.close();
    std::string urlJson = "https://" + ipcamera + ":4004/api/event/persondetection?lastId="+ std::to_string(lastId) + "&access_token=" + this->access_token;
    std::string urlFrame = "https://"+ ipcamera + ":4004/api/event/frame/persondetection/";
    HttpSession* jsonSession = new HttpSession();
    std::fstream myfile;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char timer[70];
    sprintf(timer, "%02d:%02d:%02d:%02d:%02d:%02d", ltm->tm_mday,ltm->tm_mon + 1,ltm->tm_year + 1900 ,ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    std::string Time= std::string(timer);
    // std::string day = std::to_string(ltm->tm_mday) + "-" + std::to_string(ltm->tm_mon);
    std::string path = "../Json_Event/" + ipcamera + "/personcount.txt";
    std::cout << "path = " << path << std::endl;
    jsonSession->setUrl(urlJson);
    jsonSession->addHeader("Content-Type: application/json");
    jsonSession->start();

    try {
        std::string message((const char *)jsonSession->getData(), jsonSession->getSize());
        auto j = json::parse(message);
        myfile.open(path, std::ios::out | std::ios::app);
        if (myfile.is_open()){
        myfile << Time;
        myfile << "\n";    
        myfile << message;
        myfile << "\n"; 
        }
        myfile.close();
        if (message != "[]"){
            std::cout << "j.size() = " << j.size() << std::endl;
            for (int i = j.size() - 1; i > -1; i--) {
                // std::cout << "adfkadjsfklasd" << std::endl;
            // for (auto event : j) {
                // int monitorId = event["monitor_id"];
                std::vector<cv::Rect> boxes;
                auto jlocations = j[i]["extras"]["objects"];
                for (auto jlocations1 : jlocations){
                    auto p1 = jlocations1["locations"];
                    cv::Rect box(p1[0], p1[1], p1[2], p1[3]);
                    boxes.push_back(box);
                }  
                // for (auto jlocation : jlocations) {
                //     cv::Rect box(jlocation[0], jlocation[1], jlocation[2], jlocation[3]);
                //     boxes.push_back(box);
                // }
                // int frame = event["frame"];
                int EventId = j[i]["eventId"];
                std::cout <<" eventId = " << j[i]["eventId"] << std::endl;
                std::string eventId = j[i]["image_id"];
                std::cout << "imageID = "<<eventId << std::endl;
                std::string time = j[i]["time"];
                    std::cout << "--------CountEvent-------" << std::endl;
                    CountEvent* newEvent = new CountEvent( boxes, time, eventId, EventId, ipcamera);
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
            std::ofstream file;
            file.open("../Data_EventId/" + ipcamera + "/personcount.txt");
                    if(file.is_open()){
                        file << j[0]["eventId"] << std::endl;
                        std::cout << "lastId new = "<< j[0]["eventId"] << std::endl;
                }
            file.close(); 
        }   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Process Events Successfull" << std::endl;
    delete jsonSession;
}

