//
//  FaceMaskProcessor.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 05/08/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//
#ifndef FaceMaskProcessor_hpp
#define FaceMaskProcessor_hpp

#include <string>
#include <vector>
#include <opencv2/freetype.hpp>

#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"
// #include "GlobalConfig.hpp"

class FaceMaskProcessor : public Processor {
public:
    FaceMaskProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    ~FaceMaskProcessor();
    virtual void process(Mat& frame);
    
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;

    void displayFaceMaskEvent(cv::Mat& frame);
    void displayNoFaceMaskEvent(cv::Mat& frame);
};

#endif