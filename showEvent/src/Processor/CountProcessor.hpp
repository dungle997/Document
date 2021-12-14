//
//  CountProcessor.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef CountProcessor_hpp
#define CountProcessor_hpp


#include <string>
#include <vector>
#include <opencv2/freetype.hpp>

#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"
// #include "GlobalConfig.hpp"

class CountProcessor: public Processor {
public:
    CountProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    virtual ~CountProcessor();
    virtual void process(Mat& frame);
    
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;
};


#endif /* CountProcessor_hpp */
