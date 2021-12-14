//
//  CowEvent.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef CowEvent_hpp
#define CowEvent_hpp

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class CowEvent {
public:
    CowEvent(int cameraId, const std::vector<cv::Rect>& boxes, const std::string& time, std::string frame);
    ~CowEvent();
    
    void update(const cv::Mat& image);
    
    int cameraId;
    std::vector<cv::Rect> boxes;
    std::string time;
    std::string frame;
    cv::Mat image;
};

#endif /* CowEvent_hpp */
