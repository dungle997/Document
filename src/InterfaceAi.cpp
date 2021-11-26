#include "InterfaceAi.hpp"

InterfaceAI::InterfaceAI(){
    std::cout << "Contructor InterfaceAI" << std::endl;
    httpServer = new HttpServer();
    while (true)
    {
        httpServer->loop();
    }
}
InterfaceAI::~InterfaceAI(){
    std::cout << "Destructor InterfaceAI" << std::endl;
}