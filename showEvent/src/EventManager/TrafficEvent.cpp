//
//  CountEvent.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "TrafficEvent.hpp"

TrafficEvent::TrafficEvent(int cameraId, int countTraffic, const std::string& time, std::string frame,const std::vector<cv::Rect>& boxes) {
    this->cameraId = cameraId;
    this->countTraffic = countTraffic;
    this->boxes = boxes;
    this->time = time;
    this->frame = frame;
    std::cout << "Add count event with count: " << this->boxes.size() << std::endl;
}

TrafficEvent::~TrafficEvent() {
    
}

void TrafficEvent::update(const cv::Mat& image) {
    this->image = image;
    // Draw box
    for (auto box: this->boxes) {
        cv::rectangle(this->image, box, cv::Scalar(0, 255, 0), 4);
    }
}
