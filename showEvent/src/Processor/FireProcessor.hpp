//
//  FireProcessor.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 19/08/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//
#ifndef FireProcessor_hpp
#define FireProcessor_hpp

#include <string>
#include <vector>

#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"

class FireProcessor: public Processor {
public:
    FireProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    virtual ~FireProcessor();
    virtual void process(Mat& frame);
    
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;
};


#endif /* CountProcessor_hpp */