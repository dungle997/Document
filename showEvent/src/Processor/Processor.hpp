//
//  Processor.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 14/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef Processor_hpp
#define Processor_hpp

#include <opencv2/opencv.hpp>
#include "../Config/config.h"
#include "../Render/DisplayBoard.hpp"
#include "../EventManager/EventManager.hpp"
#include "LoadProcessor/GlobalConfig.hpp"

using namespace cv;

class Processor {
public:
    Processor();
    virtual ~Processor();
    virtual void process(Mat& frame) = 0;
    virtual void showLogo(cv::Mat& frame, int& px, int& py);
};

#endif /* Processor_hpp */
