//
//  FaceEvent.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "FaceEvent.hpp"

FaceEvent::FaceEvent(int cameraId, std::vector<std::string> profileId, std::vector<cv::Rect> rect, const std::string& time, int frame, std::string ipcamera) {
    this->cameraId = cameraId;
    this->profileId = profileId;
    this->rect = rect;
    this->ipcamera = ipcamera;
    this->time =  time;
    this->frame = frame;
}

FaceEvent::~FaceEvent() {
    
}

void FaceEvent::update(const cv::Mat& image) {
        this->image = image;
        // for (auto rec : rect){
            // cv::rectangle(this->image, rec, cv::Scalar(0,0,255),4);
            // std::cout << rec.x << std::endl;
            // std::cout << rec.y << std::endl;
            // std::cout << rec.width << std::endl;
            // std::cout << rec.height << std::endl;
            // std::cout << "-------------------------------" << std::endl;

        // }
        // cv::addWeighted(this->portrait(roiPortrait), 0.0, vipIcon(roiIcon), 1.0, 0.0, this->portrait(roiPortrait));
        // std::cout << this->portrait.size() << std::endl;
        // cv::imwrite("test.jpg", this->portrait);
        for (auto Rec : this->rect) {
           
        cv::rectangle(this->image, Rec, cv::Scalar(0, 0, 255), 4);
         std::cout << "Draw Box " << std::endl;
        }
        std::string name ="";
        for (auto profile : profileId){
        name = name + profile + "_";
        }
        if (!image.empty()){
            std::cout << "Write Image " << std::endl;
        std::string nameImage = "../Event/" + this->ipcamera + "/facerecognize/" + name + "_"+this->time + "_" + std::to_string(this->frame) + ".jpg";
        cv::imwrite(nameImage, image);
        }
}