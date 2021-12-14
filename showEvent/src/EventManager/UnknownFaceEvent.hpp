//
//  UnknownFaceEvent.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 18/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef UnknownFaceEvent_hpp
#define UnknownFaceEvent_hpp

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/freetype.hpp>
#include "../Processor/LoadProcessor/GlobalConfig.hpp"


class UnknownFaceEvent {
public:
    UnknownFaceEvent(int cameraId, const cv::Rect& rect, const std::string& time, std::string frame);
    ~UnknownFaceEvent();
    
    void update(const cv::Mat& image);
    
    int cameraId;
    cv::Rect rect;
    std::string time;
    std::string frame;
    cv::Mat portrait;
};

#endif /* UnknownFaceEvent_hpp */
