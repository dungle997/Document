//
//  DistancingProcessor.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 29/07/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#ifndef DistancingProcessor_hpp
#define DistancingProcessor_hpp

#include <string>
#include <vector>
#include <opencv2/freetype.hpp>

// #include "GlobalConfig.hpp"
#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"

class DistancingProcessor: public Processor {
public:
    DistancingProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    virtual ~DistancingProcessor();
    virtual void process(Mat& frame);
    
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;
};


#endif /* DistancingProcessor_hpp */
