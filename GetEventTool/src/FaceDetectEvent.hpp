//
//  FaceDetectEvent.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef FaceDetectEvent_hpp
#define FaceDetectEvent_hpp

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <string>

class FaceDetectEvent {
public:
    FaceDetectEvent(int cameraId, const std::vector<cv::Rect>& boxes, const std::string& time, int frame, std::string ipcamera);
    ~FaceDetectEvent();
    
    void update(const cv::Mat& image);
    
    int cameraId;
    std::vector<cv::Rect> boxes;
    std::string time;
    std::string ipcamera;
    int frame;
    cv::Mat image;
};

#endif /* FaceDetectEvent_hpp */
