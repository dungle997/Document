//
//  LicenseEvent.cpp
//  CamHub
//1

//  Created by Pham Quang Hoa on 21/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "LicenseEvent.hpp"

LicenseEvent::LicenseEvent(std::vector<cv::Rect> rect, const std::string& time, std::string imageId,int frame,  std::vector<std::string> number, std::string ipcamera) {
    this->imageId = imageId;
    this->number = number;
    this->ipcamera = ipcamera;
    this->rect = rect;
    this->time =  time;
    this->frame = frame;
    // this->nameImage = nameImage;
}

LicenseEvent::~LicenseEvent() {
    
}

void LicenseEvent::update(const cv::Mat& image) {
    this->image = image;
    std::string name = "";
    for (auto numbers : number){
        
        name = name + numbers; 
        
    }
    //  for (auto Rec : this->rect) {
    //     cv::rectangle(this->image, Rec, cv::Scalar(0, 67, 255), 4);
    // }
    if (!image.empty()){
    std::string nameImage = "../Event/" + this->ipcamera +"/license/" + name + "_" + this->time + "_" + std::to_string(this->frame) + ".jpg";
    cv::imwrite(nameImage, image);
    }
    // cv::Rect roi = this->rect & cv::Rect(0, 0, image.cols, image.rows);
    // if (roi.width > 0 && roi.height > 0) {
    //     cv::Mat src = image(roi);
    //     src.copyTo(this->image);
    // }
    // std::string nameImageroi = "../datalicensecut/" + this->number + "_" + this->time + "_" + std::to_string(this->frame) + ".jpg";
    // cv::imwrite(nameImageroi, this->image);

}
