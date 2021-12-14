//
//  LoadProcessor.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 04/11/2020.
//  Copyright © 2019 Nguyen Xuan Truong. All rights reserved.
//

#include "LoadProcessor.hpp"

LoadProcessor::LoadProcessor(DisplayBoard* displayBoard, EventManager* eventManager) {
    this->displayBoard = displayBoard;
    this->eventManager = eventManager;
}

LoadProcessor::~LoadProcessor() {
}

void LoadProcessor::load() {
    try {
        for (auto monitor : config.monitors) {
            if (monitor["type"] == "facerecognize") {
                ProfileManager* profileManager = new ProfileManager();
                profileManager->load();
                FaceProcessor* faceProcessor = new FaceProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"],profileManager, this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], faceProcessor);
                rtspThread->start();
            }
            
            if (monitor["type"] == "personcount") {
                CountProcessor* countProcessor = new CountProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"], this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], countProcessor);
                rtspThread->start();
            }
             if (monitor["type"] == "alarm") {
                AlarmProcessor* alarmProcessor = new AlarmProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"], this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], alarmProcessor);
                rtspThread->start();
            }
            if (monitor["type"] == "cowdetect") {
                CowProcessor* cowProcessor = new CowProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"], this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], cowProcessor);
                rtspThread->start();
            }

            if (monitor["type"] == "socialdistancing") {
                DistancingProcessor* distanceProcessor = new DistancingProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"], this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], distanceProcessor);
                rtspThread->start();
            }

            if (monitor["type"] == "facemask") {
                FaceMaskProcessor* processor = new FaceMaskProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"], this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], processor);
                rtspThread->start();
            }

            if (monitor["type"] == "objectdetect") {
                ObjectProcessor* processor = new ObjectProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"], this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], processor);
                rtspThread->start();
            }

            if (monitor["type"] == "firedetect") {
                FireProcessor* processor = new FireProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"], this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], processor);
                rtspThread->start();
            }

            if (monitor["type"] == "display") {
                DisplayProcessor* processor = new DisplayProcessor( this->displayBoard, monitor["screenId"]);
                RtspThread* rtspThread = new RtspThread(monitor["url"], processor);
                rtspThread->start();
            }

            if (monitor["type"] == "license") {
                LicenseProcessor* processor = new LicenseProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"], this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], processor);
                rtspThread->start();
            }
            if (monitor["type"] == "facedetect"){
                FaceDetectProcessor* processor = new FaceDetectProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"], this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], processor);
                rtspThread->start();
            }
            if (monitor["type"] == "welcome") {
                ProfileManager* profileManager = new ProfileManager();
                profileManager->load();
                WelcomeSceenProcessor* processor = new WelcomeSceenProcessor(monitor["cameraId"], this->displayBoard, monitor["screenId"],profileManager, this->eventManager);
                RtspThread* rtspThread = new RtspThread(monitor["url"], processor);
                // threadManager.push_back(rtspThread);
                rtspThread->start();
                std::cout << "Create Welcome Monitor in screen " << monitor["screenId"] <<std::endl;
}
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}