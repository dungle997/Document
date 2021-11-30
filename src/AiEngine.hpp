#pragma once 
#include <iostream>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

class AiEngine{
    private:
        pthread_t handing_thread_id;
        static void* AI_Handling(void* arg);
    public:
        AiEngine();
        virtual ~AiEngine();
        virtual void initAI() = 0;
        virtual void executeAI() = 0;
        
};