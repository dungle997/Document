#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <pthread.h>
#include "HttpServer.hpp"

class InterfaceAI{
    public:
    InterfaceAI();
    ~InterfaceAI();
    private:
    HttpServer* httpServer = nullptr;
    pthread_t thread_id;
    static void* thread_loop(void* args);


};