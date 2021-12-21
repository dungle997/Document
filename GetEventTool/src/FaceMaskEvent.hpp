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
#include <vector>

class FaceMaskEvent {
public:
    FaceMaskEvent(int cameraId, std::vector<cv::Rect>& rect, std::string time, int frame, std::string ipcamera, std::vector<int> fmask);
    ~FaceMaskEvent();

    void update(const cv::Mat& image);
    int cameraId;
    std::vector<int> fmask;
    std::vector<cv::Rect> rect;
    std::string time;
    std::string ipcamera;
    std::string day;
    int frame;
    cv::Mat image;
};

#endif 