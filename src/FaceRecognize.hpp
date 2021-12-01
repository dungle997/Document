#pragma once 
#include "AiEngine.hpp"
// #include "Processor.hpp"

class FaceRecognize : public AiEngine{
    private: 
        std::string type;
        bool status;
    public: 
        FaceRecognize(Processor& p);
        ~FaceRecognize();
        virtual bool initAI() override;
        virtual void executeAI() override;
};