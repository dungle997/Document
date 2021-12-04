#pragma once 
#include <iostream>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <mutex>
#include <condition_variable>
#include "Processor.hpp"

class AiEngine : public Processor{
    private:
        std::mutex cv_m;
        pthread_t handing_thread_id;
        static void* AI_Handling(void* arg);
    public:
        AiEngine(Processor& p);
        virtual ~AiEngine();
        virtual bool initAI() = 0;
        virtual void executeAI() = 0;
        virtual void stopThread() override;
    protected:
        std::condition_variable cv_init_done;
        bool init_done = false;
        
};