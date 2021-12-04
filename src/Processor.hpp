#pragma once 
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
class Processor{
    public:
        Processor(std::string type, bool status) : type(type), status(status){
            std::cout << "Init Processor normal way" << std::endl;
        }
        Processor(const Processor& p){
            this->type   = p.type;
            this->status = p.status; 
            std::cout << "Init Processor new way" << std::endl;
        }
        Processor(){}
        virtual ~Processor(){ std::cout << "Processor Destroyed" << std::endl;}
        std::string type;
        bool status;
        virtual void stopThread(){}
};
// class Processor{
//     public:
//         Processor(std::string type, bool status);
//         Processor(const Processor& p);
//         virtual ~Processor();
//         std::string type;
//         bool status;
// };
