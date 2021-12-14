//
//  WelcomeSceenProcessor.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 21/12/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#ifndef WelcomeSceenProcessor_hpp
#define WelcomeSceenProcessor_hpp

#include <string>
#include <vector>
#include <opencv2/freetype.hpp>

#include "Processor.hpp"
// #include "FaceEvent.hpp"
// #include "../Render/DisplayBoard.hpp"
#include "ProfileManager/ProfileManager.hpp"
// #include "EventManager.hpp"
// #include "GlobalConfig.hpp"

class WelcomeSceenProcessor: public Processor {
public:
    WelcomeSceenProcessor(int cameraId, DisplayBoard* displayBoard, int index, ProfileManager* profileManager, EventManager* eventManager);
    ~WelcomeSceenProcessor();
    virtual void process(Mat& frame);
    void displayProfileImage(cv::Mat& frame);
    void displayFaceEvent(cv::Mat& frame);

    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    ProfileManager* profileManager;
    EventManager* eventManager;
    cv::Ptr<cv::freetype::FreeType2> ft2;
};

#endif /*WelcomeSceenProcessor_hpp*/