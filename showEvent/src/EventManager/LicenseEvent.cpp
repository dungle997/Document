//
//  LicenseEvent.cpp
//  CamHub
//1

//  Created by Pham Quang Hoa on 21/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "LicenseEvent.hpp"

LicenseEvent::LicenseEvent(int cameraId, const std::string& number, const cv::Rect& rect, const std::string& time, std::string frame, std::string nameImage) {
    this->cameraId = cameraId;
    this->number = number;
    this->rect = rect;
    this->time =  time;
    this->frame = frame;
    this->nameImage = nameImage;
}

LicenseEvent::~LicenseEvent() {
    
}

void LicenseEvent::update(const cv::Mat& image) {
    if ((image.cols == 1920 && image.rows == 1080) || (image.cols == 1280 && image.rows == 720) || (image.cols == 640 && image.rows == 480)){
        // std::string nameImage = "../datalicense/" + this->number + "_" + this->time + "_" + std::to_string(this->frame) + ".jpg";
        // cv::imwrite(nameImage, image);
        
        cv::Rect roi = this->rect & cv::Rect(0, 0, image.cols, image.rows);
        if (roi.width > 0 && roi.height > 0) {
            cv::Mat src = image(roi);
            src.copyTo(this->image);
        }
        // std::string nameImageroi = "../datalicensecut/" + this->number + "_" + this->time + "_" + std::to_string(this->frame) + ".jpg";
        // cv::imwrite(nameImageroi, this->image);
    }
    else{
        this->image = image;
    }
    

}
