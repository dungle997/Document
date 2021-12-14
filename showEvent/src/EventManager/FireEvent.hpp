//
//  FireEvent.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 19/08/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef FireEvent_hpp
#define FireEvent_hpp

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class FireEvent {
public:
    FireEvent(int cameraId, const std::vector<cv::Rect>& boxes, const std::string& time, std::string frame);
    ~FireEvent();
    
    void update(const cv::Mat& image);
    
    int cameraId;
    std::vector<cv::Rect> boxes;
    std::string time;
    std::string frame;
    cv::Mat image;
};

#endif /* FireEvent_hpp */