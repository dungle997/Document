#include "InterfaceAi.hpp"
void *InterfaceAI::thread_loop(void* args){
    std::cout << "thread loop" << std::endl;
    // InterfaceAI* interfaceAI;
    // interfaceAI = new InterfaceAI();
    InterfaceAI* interfaceAI = (InterfaceAI*) args;
    // auto interfaceAI = static_cast<InterfaceAI*> (args);
    while (true){
        interfaceAI->httpServer->loop();
    }
    pthread_exit(NULL);
}

InterfaceAI::InterfaceAI(){
    std::cout << "Contructor InterfaceAI" << std::endl;
    httpServer = new HttpServer();
    pthread_create(&thread_id,NULL, thread_loop, this);
    pthread_join(thread_id, NULL);
    
}
InterfaceAI::~InterfaceAI(){
    if (this->httpServer){
        // std::cout << this->httpServer << std::endl;
        delete this->httpServer;
    }
    std::cout << "Destructor InterfaceAI" << std::endl;
}