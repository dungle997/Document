//
//  FaceProcessor.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef FaceProcessor_hpp
#define FaceProcessor_hpp

#include <string>
#include <vector>
#include <opencv2/freetype.hpp>

// #define HTTP_PORT 8015

#include "Processor.hpp"
// #include "FaceEvent.hpp"
// #include "DisplayBoard.hpp"
#include "ProfileManager/ProfileManager.hpp"
// #include "EventManager.hpp"
// #include "GlobalConfig.hpp"


class FaceProcessor: public Processor {
public:
    FaceProcessor(int cameraId, DisplayBoard* displayBoard, int index, ProfileManager* profileManager, EventManager* eventManager);
    virtual ~FaceProcessor();
    virtual void process(Mat& frame);

    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    ProfileManager* profileManager;
    EventManager* eventManager;
    
    void displayFaceEvent(Mat& frame);
    void displayUnknownFaceEvent(Mat& frame);
};

#endif /* FaceProcessor_hpp */
