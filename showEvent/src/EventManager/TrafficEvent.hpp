//
//  CountEvent.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef TrafficEvent_hpp
#define TrafficEvent_hpp

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class TrafficEvent {
public:
    TrafficEvent(int cameraId, int countTraffic, const std::string& time, std::string frame,const std::vector<cv::Rect>& boxes);
    ~TrafficEvent();
    
    void update(const cv::Mat& image);
    
    int cameraId;
    int countTraffic;
    std::vector<cv::Rect> boxes;
    std::string time;
    std::string frame;
    cv::Mat image;
};

#endif /* TrafficEvent_hpp */
