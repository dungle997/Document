//
//  FaceEvent.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef FaceEvent_hpp
#define FaceEvent_hpp

#include <string>
#include <opencv2/opencv.hpp>

class FaceEvent {
public:
    FaceEvent(int cameraId, std::string profileId, const cv::Rect& rect, const std::string& time, const std::string& day, std::string frame);
    ~FaceEvent();
    
    void update(const cv::Mat& image);
    int cameraId;
    std::string profileId;
    cv::Rect rect;
    std::string time;
    std::string day;
    std::string frame;
    cv::Mat portrait;
};

#endif /* FaceEvent_hpp */
