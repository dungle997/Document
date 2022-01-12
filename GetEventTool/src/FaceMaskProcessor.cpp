#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
// #include "FaceMaskEvent.hpp"
#include "FaceMaskProcessor.hpp"
#include <fstream>
#include <ctime>
#include <string>

FaceMaskProcessor::FaceMaskProcessor() : GetImageEngine(){
    
}
FaceMaskProcessor::~FaceMaskProcessor(){

}
void FaceMaskProcessor::handleRequest(std::string& message){
    std::cout << "Get FaceMask Event" << std::endl;
    auto j = json::parse(message);
    if (message != "[]"){
        std::cout << "j.size() = " << j.size() << std::endl;
        for (int i = j.size() - 1; i > -1; i--) {
            extractInformation(message, i);
            auto jFmask = j[i]["extras"]["objects"];
            for (auto jfmask : jFmask){
                auto fmask1 = jfmask["fmask"];
                this->fmask.push_back(fmask1);
            }
            this->getImage(this->currentFrameUrl);
            drawBox();
            std::string name = nameImage();
            writeImage(name);
            this->boxes.clear();
            this->fmask.clear();
        }
    } 
}
std::string FaceMaskProcessor::nameImage(){
    std::string name ="";
    for (auto Fmask : fmask){
        name = name + std::to_string(Fmask) + "_";
    }
    std::string nameImage = "../Event/" + this->ipcamera + "/facemask/" + this->timeEvent + "_" + name +"_" + std::to_string(this->eventID) + ".jpg";
    return nameImage;
}

