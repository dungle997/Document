#include "MonitorManager.hpp"

MonitorManager::MonitorManager(){
    std::cout << "Constructor Monitor Manager" << std::endl;
}
MonitorManager::~MonitorManager(){
    std::cout << "Destructor Monitor Manager" << std::endl;
}
void MonitorManager::addProcessor(std::string& type, bool& status){
    this->removeProcessor();
    Processor p(type, status);
    AiEngine* obj = nullptr;
    if (type == "facerecognize"){
        obj = new FaceRecognize(p);   
    }
    this->processors.push_back(obj);
}
void MonitorManager::removeProcessor(){
    std::cout << "processors.size() = " << processors.size() << std::endl;
    for (size_t i = 0 ; i<this->processors.size(); i++){
        this->processors[i]->stopThread();
        delete this->processors[i];
        this->processors.erase(this->processors.begin());
    }
}