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
#include <vector>
#include <string>

class LicenseEvent
{
public:
    LicenseEvent(std::vector<cv::Rect> rect, const std::string &time,std::string imageId, int frame, std::vector<std::string> number, std::string ipcamera);
    ~LicenseEvent();

    void update(const cv::Mat &image);

    std::string imageId;
    std::vector<std::string> number;
    std::vector<cv::Rect> rect;
    std::string time;
    std::string ipcamera;
    int frame;
    cv::Mat image;
    // std::string nameImage;
};

#endif /* LicenseEvent_hpp */
