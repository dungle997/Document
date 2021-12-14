//
//  CountProcessor.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef FaceDetectProcessor_hpp
#define FaceDetectProcessor_hpp

#include <string>
#include <vector>

#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"

class FaceDetectProcessor: public Processor {
public:
    FaceDetectProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    virtual ~FaceDetectProcessor();
    virtual void process(Mat& frame);
    
    std::string cameraIp;
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;
};


#endif /* FaceDectectProcessor_hpp */
