#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
// #include "LicenseEvent.hpp"
#include "LicenseProcessor.hpp"
#include <fstream>
#include <ctime>
#include <string>
LicenseProcessor::LicenseProcessor() : GetImageEngine(){

}
LicenseProcessor::~LicenseProcessor(){
    
}
void LicenseProcessor::handleRequest(std::string& message){
    std::cout << "Get Lisense Event" << std::endl;
    auto j = json::parse(message);
    if (message != "[]"){
        std::cout << "j.size() = " << j.size() << std::endl;
        for (int i = j.size() - 1; i > -1; i--) {
            extractInformation(message, i);
            auto jLicenses = j[i]["extras"]["objects"];
            for (auto jLicense : jLicenses){
                auto license1 = jLicense["license"];
                if (license1.is_null()){ 
                    auto license2 = license1["label"];
                    this->licenses.push_back(license2);
                }
            }
            this->getImage(this->currentFrameUrl);
            drawBox();
            std::string name = nameImage();
            writeImage(name);
            this->boxes.clear();
            this->licenses.clear();
        }
    } 
}
std::string LicenseProcessor::nameImage(){
    std::string name = "";
    if (this->licenses.size()){
        for (auto numbers : this->licenses){
            name = name + numbers;   
        }
    }
    std::string nameImage = "../Event/" + this->ipcamera +"/vehicledetection/" + name + "_" + this->timeEvent + "_" + std::to_string(this->eventID) + ".jpg";
    return nameImage;
}

