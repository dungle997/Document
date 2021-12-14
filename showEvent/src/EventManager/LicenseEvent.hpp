//
//  LicenseEvent.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 21/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef LicenseEvent_hpp
#define LicenseEvent_hpp

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class LicenseEvent {
public:
    LicenseEvent(int cameraId, const std::string& number, const cv::Rect& rect, const std::string& time, std::string frame, std::string nameImage);
    ~LicenseEvent();
    
    void update(const cv::Mat& image);
    
    int cameraId;
    std::string number;
    cv::Rect rect;
    std::string time;
    std::string frame;
    cv::Mat image;
    std::string nameImage;
};

#endif /* LicenseEvent_hpp */
