
#include "CountProcessor.hpp"

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
            extractInformation(message, i);
            this->getImage(this->currentFrameUrl);
            drawBox();
            std::string name = nameImage();
            writeImage(name);
            this->boxes.clear();
        }
    }   
}
std::string CountProcessor::nameImage(){
    int a = this->boxes.size();
    std::string nameImage = "../Event/" + this->ipcamera + "/persondetection/" + this->timeEvent + "_" + std::to_string(this->eventID) + "_size_" + std::to_string(a) + ".jpg";
    return nameImage;
}

