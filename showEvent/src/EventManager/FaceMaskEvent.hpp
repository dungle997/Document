//
//  FaceMaskEvent.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 05/08/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#ifndef FaceMaskEvent_hpp
#define FaceMaskEvent_hpp

#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/freetype.hpp>
#include "../Processor/LoadProcessor/GlobalConfig.hpp"

class FaceMaskEvent {
public:
    FaceMaskEvent(int cameraId, cv::Rect rect, std::string time, std::string frame);
    ~FaceMaskEvent();

    void update(const cv::Mat& image);
    int cameraId;
    cv::Rect rect;
    std::string time;
    std::string day;
    std::string frame;
    cv::Mat portrait;
};

#endif 