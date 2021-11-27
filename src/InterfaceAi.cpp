#include "InterfaceAi.hpp"
void InterfaceAI::thread_loop(){
    std::cout << "thread loop" << std::endl;
    InterfaceAI* interfaceAI;
    while (true)
    {
        interfaceAI->httpServer->loop();
    }
}

InterfaceAI::InterfaceAI(){
    std::cout << "Contructor InterfaceAI" << std::endl;
    httpServer = new HttpServer();
    pthread_create(&thread_id,NULL, thread_loop, NULL);
    pthread_join(thread_id, NULL);
}
InterfaceAI::~InterfaceAI(){
    std::cout << "Destructor InterfaceAI" << std::endl;
}
void 