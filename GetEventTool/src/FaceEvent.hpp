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
#include <vector>

class FaceEvent {
public:
    FaceEvent(int cameraId, std::vector<std::string> profileId, std::vector<cv::Rect> rect, const std::string& time, int frame, std::string ipcamera);
    ~FaceEvent();
    
    void update(const cv::Mat& image);
    int cameraId;
    std::vector<std::string> profileId;
    std::vector<cv::Rect> rect;
    std::string time;
    std::string ipcamera;
    int frame;
    cv::Mat image;
};

#endif /* FaceEvent_hpp */
