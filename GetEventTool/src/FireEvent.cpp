//
//  FireEvent.cpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 19/08/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "FireEvent.hpp"

FireEvent::FireEvent(int cameraId, const std::vector<cv::Rect>& boxes, const std::string& time, int frame, std::string ipcamera) {
    this->cameraId = cameraId;
    this->boxes = boxes;
    this->time = time;
    this->ipcamera = ipcamera;
    this->frame = frame;
}

FireEvent::~FireEvent() {
    
}

void FireEvent::update(const cv::Mat& image) {
    this->image = image;
    // Draw box
    // cv::Size textTimeSize = cv::getTextSize(this->time, cv::FONT_HERSHEY_TRIPLEX, 2, 3, 0);

    // cv::putText(this->image, this->time, cv::Point(this->image.cols - textTimeSize.width - 30, 40 + textTimeSize.height), cv::FONT_HERSHEY_TRIPLEX, 2, cv::Scalar(0, 67, 255), 3);
    // cv::putText(this->image, this->time, cv::Point(this->image.cols - textTimeSize.width - 29, 41 + textTimeSize.height), cv::FONT_HERSHEY_TRIPLEX, 2, cv::Scalar(0, 70, 255), 3);
    for (auto box: this->boxes) {
        cv::rectangle(this->image, box, cv::Scalar(0, 67, 255), 4);
    }
    if (!image.empty()){
    std::string nameImage = "../Event/" + this->ipcamera +"/firedetect/" + this->time + "_" + std::to_string(this->frame) + ".jpg";
    cv::imwrite(nameImage, image);
    }
}
