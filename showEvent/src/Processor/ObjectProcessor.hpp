//
//  ObjectProcessor.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 05/09/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#ifndef ObjectProcessor_hpp
#define ObjectProcessor_hpp

#include <string>
#include <vector>

#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"
// #include "GlobalConfig.hpp"

class ObjectProcessor: public Processor {
public:
    ObjectProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    virtual ~ObjectProcessor();
    virtual void process(Mat& frame);
    
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;
    std::string cameraIp;
};


#endif /* CountProcessor_hpp */
