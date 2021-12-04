#include "AiEngine.hpp"

AiEngine::AiEngine(Processor& p) : Processor(p) {
    pthread_create(&this->handing_thread_id, NULL, AI_Handling,this);
    std::cout << "Constructor AI Engines" << std::endl;
}
AiEngine::~AiEngine(){
    std::cout << "AiEngine Detroyed" << std::endl;
}
void* AiEngine::AI_Handling(void* arg){
    std::cout << "This is a new thread in AI_Handling" << std::endl;
    auto process = static_cast<AiEngine*>(arg);
    // wait constructor init
    std::unique_lock<std::mutex> lk(process->cv_m);
    process->cv_init_done.wait(lk, [=]{return process->init_done;});
    //
    bool init_finish = process->initAI();
    if (!init_finish){
        std::cout << "init AI fail"<< std::endl;
        goto EXIT_THREAD;
    }
    while (process->status == true){
        std::cout << "Runing AI ...." << std::endl;
        process->executeAI();
    }
    EXIT_THREAD:
    pthread_exit(NULL);
}
void AiEngine::stopThread(){
    Processor::status = false;
    pthread_join(this->handing_thread_id, NULL);
}