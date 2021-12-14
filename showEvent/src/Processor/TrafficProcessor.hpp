//
//  CountProcessor.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef TrafficProcessor_hpp
#define TrafficProcessor_hpp

#include <string>
#include <vector>

#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"

class TrafficProcessor: public Processor {
public:
    TrafficProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    virtual ~TrafficProcessor();
    virtual void process(Mat& frame);
    
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;
};


#endif /* TrafficProcessor_hpp */
