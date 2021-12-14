//
//  LicenseProcessor.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 21/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef LicenseProcessor_hpp
#define LicenseProcessor_hpp

#include <string>
#include <vector>
#include <opencv2/freetype.hpp>

#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"

class LicenseProcessor: public Processor {
public:
    LicenseProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    ~LicenseProcessor();
    virtual void process(Mat& frame);
    
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;
};

#endif /* LicenseProcessor_hpp */
