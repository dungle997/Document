#pragma once
#include <string.h>
#include <iostream>
#include "AiEngine.hpp"
#include "FaceRecognize.hpp"
#include "Processor.hpp"

class MonitorManager{
    public:
        MonitorManager();
        ~MonitorManager();
        void addProcessor(std::string& type, bool& status);
    private:
        
};