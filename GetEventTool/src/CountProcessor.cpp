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
    std::cout << "Destructor CountProcessor" << std::endl;
}
void CountProcessor::handleRequest(std::string& message){
    std::cout << "Get Count Event" << std::endl;
    auto j = json::parse(message);
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
            CountEvent* newEvent = new CountEvent( boxes, time, EventId, this->ipcamera);
            std::string currentFrameUrl = urlFrame + eventId + "?access_token=" + this->access_token;
            this->getImage(currentFrameUrl);
            // HttpSession* imageSession = new HttpSession();
            newEvent->update(this->imageEvent);
            delete newEvent;
        }
        std::cout << "lastId new = "<< j[0]["eventId"] << std::endl;
        this->lastID = j[0]["eventId"];
    }   
}

