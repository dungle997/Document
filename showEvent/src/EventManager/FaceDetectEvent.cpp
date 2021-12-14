//
//  CountEvent.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "FaceDetectEvent.hpp"

FaceDetectEvent::FaceDetectEvent(int cameraId, const std::vector<cv::Rect>& boxes, const std::string& time, std::string frame) {
    this->cameraId = cameraId;
    this->boxes = boxes;
    this->time = time;
    this->frame = frame;
   // std::cout << "Add count event with count: " << this->boxes.size() << std::endl;
}

FaceDetectEvent::~FaceDetectEvent() {
    
}

void FaceDetectEvent::update(const cv::Mat& image) {
    this->image = image;
    cv::Size textTimeSize = cv::getTextSize(this->time, cv::FONT_HERSHEY_TRIPLEX, 2, 3, 0);

    cv::putText(this->image, this->time, cv::Point(this->image.cols - textTimeSize.width - 30, 40 + textTimeSize.height), cv::FONT_HERSHEY_TRIPLEX, 2, cv::Scalar(0, 67, 255), 3);
    // Draw box
    for (auto box: this->boxes) {
        cv::rectangle(this->image, box, cv::Scalar(0, 255, 0), 4);
    }
}
