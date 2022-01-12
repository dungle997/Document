
#include "FaceProcessor.hpp"

FaceProcessor::FaceProcessor() : GetImageEngine(){

}
FaceProcessor::~FaceProcessor(){

}
void FaceProcessor::handleRequest(std::string& message){
    std::cout << "Get Face Event" << std::endl;
    auto j = json::parse(message);
    if (message != "[]"){
        std::cout << "j.size() = " << j.size() << std::endl;
        for (int i = j.size() - 1; i > -1; i--) {
            extractInformation(message, i);
            auto jprofileId = j[i]["extras"]["objects"];
            for (auto jprofileid1 : jprofileId){
                auto profileId2 = jprofileid1["profileId"];
                this->profileId.push_back(profileId2);
            }
            this->getImage(this->currentFrameUrl);
            drawBox();
            std::string name = nameImage();
            writeImage(name);
            this->boxes.clear();
            this->profileId.clear();
        }
    } 
}
std::string FaceProcessor::nameImage(){
    std::string name ="";
    for (auto profile : profileId){
        name = name + profile + "_";
    }
    std::string nameImage = "../Event/" + this->ipcamera + "/facerecognition/" + name + "_"+this->timeEvent + "_" + std::to_string(this->eventID) + ".jpg";
    return nameImage;
}

