//
//  CountEvent.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef CountEvent_hpp
#define CountEvent_hpp

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <string>
#include "CountProcessor.hpp"

class CountEvent {
public:
    CountEvent(const std::vector<cv::Rect>& boxes, const std::string& time, int eventId, std::string ipcamera);
    ~CountEvent();
    
    void update(const cv::Mat& image);
    
    // int cameraId;
    std::vector<cv::Rect> boxes;
    std::string time;
    std::string ipcamera;
    // std::string frame;
    int eventId;
    cv::Mat image;
};

#endif /* CountEvent_hpp */
