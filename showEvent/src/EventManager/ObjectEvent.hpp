//
//  ObjectEvent.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 05/09/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#ifndef ObjectEvent_hpp
#define ObjectEvent_hpp

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class ObjectEvent {
public:
    ObjectEvent(int cameraId, const std::vector<std::string>& objectName,const std::vector<cv::Rect>& boxes, const std::string& time, std::string frame);
    ~ObjectEvent();
    
    void update(const cv::Mat& image);
    
    int cameraId;
    std::vector<std::string> objectName;
    std::vector<cv::Rect> boxes;
    std::string time;
    std::string frame;
    cv::Mat image;
};

#endif /* ObjectEvent_hpp */
