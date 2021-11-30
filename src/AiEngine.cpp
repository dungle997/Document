#include "AiEngine.hpp"

AiEngine::AiEngine() : Processor() {
    pthread_create(&this->handing_thread_id, NULL, AI_Handling,this);
    std::cout << "Constructor AI Engines" << std::endl;
}
AiEngine::~AiEngine(){
    std::cout << "AiEngine Detroyed" << std::endl;
}
void* AiEngine::AI_Handling(void* arg){
    std::cout << "This is a new thread in AI_Handling" << std::endl;
    auto process = static_cast<AiEngine*>(arg);
    process->initAI();
    process->executeAI();
    pthread_exit(NULL);
}