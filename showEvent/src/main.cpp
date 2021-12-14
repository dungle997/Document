//
//  main.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 11/1/19.
//  Copyright © 2019 Pham Quang Hoa. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <thread>
#include <deque>
#include <mutex>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#include "Processor/LoadProcessor/GlobalConfig.hpp"
#include "Render/DisplayBoard.hpp"
#include "Processor/ObjectManager/ObjectManager.hpp"
#include "Processor/LoadProcessor/LoadProcessor.hpp"

#include "Render/OpenCV/OpenCVRenderer.hpp"
#include "Render/OpenGL/OpenGLRenderer.hpp"
#include "EventManager/EventManager.hpp"
#include "Protocol/HttpServer.hpp"



using namespace cv;
using namespace std;


ObjectManager* objectManager = NULL;
Renderer* renderer = NULL;
DisplayBoard* displayBoard = NULL;
EventManager* eventManager = NULL;
HttpServer* httpServer = NULL;
LoadProcessor* loadProcessor = NULL;



void selectView(int view) {
    // if (view == 1) {
    //     displayBoard->setGridSize(2, 2);
    //     processor0->index = 0;
    //     // processor1->index = 0;
    //     processor2->index = 1;
    //     // processor3->index = 3;
    //     processor4->index = 2;
    //     processor5->index = 3;
    //     // processor6->index = 4;
    // }
    // if (view == 2) {
    //     displayBoard->setGridSize(1, 1);
    //     processor0->index = 0;
    //     // processor1->index = 0;
    //     processor2->index = 1;
    //     // processor3->index = 1;
    //     processor4->index = 1;
    //     processor5->index = 1;
    //     // processor6->index = 1;
    // }
    // else if (view == 3) {
    //     displayBoard->setGridSize(1, 1);
    //     processor0->index = 1;
    //     // processor1->index = 1;
    //     processor2->index = 0;
    //     // processor3->index = 1;
    //     processor4->index = 1;
    //     processor5->index = 1;
    //     // processor6->index = 0;
    // }
    // else if (view == 4) {
    //     displayBoard->setGridSize(1, 1);
    //     processor0->index = 1;
    //     // processor1->index = 1;
    //     processor2->index = 1;
    //     // processor3->index = 1;
    //     processor4->index = 0;
    //     processor5->index = 1;
    // }
    // else if (view == 5) {
    //     displayBoard->setGridSize(1, 1);
    //     processor0->index = 1;
    //     // processor1->index = 1;
    //     processor2->index = 1;
    //     // processor3->index = 1;
    //     processor4->index = 1;
    //     processor5->index = 0;
    // }
    // else if (view == 6) {
    //     displayBoard->setGridSize(1, 1);
    //     processor0->index = 1;
    //     processor1->index = 0;
    //     processor2->index = 1;
    //     processor3->index = 1;
    //     processor4->index = 1;
    //     processor5->index = 1;
    // }
    // else if (view == 7) {
    //     displayBoard->setGridSize(1, 1);
    //     processor0->index = 1;
    //     processor1->index = 1;
    //     processor2->index = 1;
    //     processor3->index = 0;
    //     processor4->index = 1;
    //     processor5->index = 1;
    // }
}

int main(int argc, char** argv) {


    config.load();

    renderer = new OpenGLRenderer();
    
    displayBoard = new DisplayBoard();
    int resolution = 1;
    if (config.isFullHD) {
        resolution = 1;
    }
    else {
        resolution = 2;
    }
       
    displayBoard->setClientSize(1920 * resolution, 1080 * resolution);
    displayBoard->setGridSize(config.row, config.cols);
    displayBoard->setRenderer(renderer);

    objectManager = new ObjectManager();
    objectManager->load();

    eventManager = new EventManager();
    httpServer = new HttpServer(eventManager, objectManager);

    loadProcessor = new LoadProcessor(displayBoard, eventManager);
    loadProcessor->load();
    
    while (renderer->running()) {
        displayBoard->loop();
        httpServer->loop();
        // usleep(10);
    }

    return 0;
}
