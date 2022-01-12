#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "FireProcessor.hpp"
#include <fstream>
#include <ctime>
#include <string>

FireProcessor::FireProcessor() : GetImageEngine(){

}
FireProcessor::~FireProcessor(){
    
}
void FireProcessor::handleRequest(std::string& message){
    std::cout << "Get Fire Event" << std::endl;
    auto j = json::parse(message);
    if (message != "[]"){
        std::cout << "j.size() = " << j.size() << std::endl;
        for (int i = j.size() - 1; i > -1; i--) {
            extractInformation(message, i);
            this->getImage(this->currentFrameUrl);
            drawBox();
            std::string name = nameImage();
            writeImage(name);
            this->boxes.clear();
        }
    }   
}
std::string FireProcessor::nameImage(){
    std::string nameImage = "../Event/" + this->ipcamera +"/firedetect/" + this->timeEvent + "_" + std::to_string(this->eventID) + ".jpg";
    return nameImage;
}
