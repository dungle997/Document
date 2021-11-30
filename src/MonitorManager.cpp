#include "MonitorManager.hpp"

MonitorManager::MonitorManager(){
    std::cout << "Constructor Monitor Manager" << std::endl;
}
MonitorManager::~MonitorManager(){
    std::cout << "Destructor Monitor Manager" << std::endl;
}
void MonitorManager::addProcessor(std::string& type, bool& status){

    Processor p(type, status);
    AiEngine* obj = nullptr;
    if (type == "facerecognize"){
        obj = new FaceRecognize(p);   
    }
}