//
//  ObjectEvent.cpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 05/09/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#include "ObjectEvent.hpp"

ObjectEvent::ObjectEvent(int cameraId, const std::vector<std::string>& objectName, const std::vector<cv::Rect>& boxes, const std::string& time, std::string frame) {
    this->cameraId = cameraId;
    this->boxes = boxes;
    this->objectName = objectName;
    this->time = time;
    this->frame = frame;
}

ObjectEvent::~ObjectEvent() {
    
}

void ObjectEvent::update(const cv::Mat& image) {
    
    this->image = image;
    cv::Size textTimeSize = cv::getTextSize(this->time, cv::FONT_HERSHEY_TRIPLEX, 2, 3, 0);
    cv::putText(this->image, this->time, cv::Point(this->image.cols - textTimeSize.width - 30, 40 + textTimeSize.height), cv::FONT_HERSHEY_TRIPLEX, 2, cv::Scalar(0, 67, 255), 3);
    // Draw box
    int count =0;
    for (auto box: this->boxes) {
        cv::putText(this->image, this->objectName[count], cv::Point(box.x , box.y +20), cv::FONT_HERSHEY_TRIPLEX, 1, cv::Scalar(0, 67, 255), 3);
        // std::cout << this->objectName[count] << std::endl;
        cv::rectangle(this->image, box, cv::Scalar(0, 255, 0), 4);
        count ++; 
    }
    //cv::imwrite("test.jpg", image);
}
