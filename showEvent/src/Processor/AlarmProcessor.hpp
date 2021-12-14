//
//  AlarmProcessor.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef AlarmProcessor_hpp
#define AlarmProcessor_hpp


#include <string>
#include <vector>
#include <opencv2/freetype.hpp>

#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"
// #include "GlobalConfig.hpp"

class AlarmProcessor: public Processor {
public:
    AlarmProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    virtual ~AlarmProcessor();
    virtual void process(Mat& frame);
    
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;
};


#endif /* AlarmProcessor_hpp */
