//
//  NoFaceMaskEvent.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 05/08/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#ifndef NoFaceMaskEvent_hpp
#define NoFaceMaskEvent_hpp

#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/freetype.hpp>
#include "../Processor/LoadProcessor/GlobalConfig.hpp"

class NoFaceMaskEvent {
public:
    NoFaceMaskEvent(int cameraId, cv::Rect rect, std::string time, std::string frame);
    ~NoFaceMaskEvent();

    void update(const cv::Mat& image);
    int cameraId;
    cv::Rect rect;
    std::string time;
    std::string day;
    std::string frame;
    cv::Mat portrait;
};


#endif