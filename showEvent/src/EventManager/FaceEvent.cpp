//
//  FaceEvent.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "FaceEvent.hpp"

FaceEvent::FaceEvent(int cameraId, std::string profileId, const cv::Rect& rect, const std::string& time, const std::string& day, std::string frame) {
    this->cameraId = cameraId;
    this->profileId = profileId;
    this->rect = rect;
    this->day = day;
    this->time =  time;
    this->frame = frame;
}

FaceEvent::~FaceEvent() {
    
}

void FaceEvent::update(const cv::Mat& image) {
    if (image.cols > 200 && image.rows > 250){
            // calc portrait size
            int fs = this->rect.width > this->rect.height ? this->rect.width : this->rect.height;
            if(rect.width > 90 || rect.height > 90 ){
            int pw = 2 * fs;
            int ph = pw * 4 / 3;
            int cx = this->rect.x + this->rect.width / 2;
            int cy = this->rect.y + this->rect.height / 2;
            int x = cx - pw / 2;
            int y = cy - ph / 2;
            
            // check
            if (x < 0) {
                x = 0;
            }
            else if (x + pw > image.cols) {
                x = image.cols - pw;
            }
            
            if (y < 0) {
                y = 0;
            }
            else if (y + ph > image.rows) {
                y = image.rows - ph;
            }
            
            // // add bouding box 
            // cv::rectangle(image, rect, cv::Scalar(0, 255, 0),4);
            // int lineHeight = 8;

            // cv::line(image, rect.tl(), cv::Point(rect.tl().x + lineHeight, rect.tl().y), cv::Scalar(0, 255, 0),2);
            // cv::line(image, rect.tl(), cv::Point(rect.tl().x , rect.tl().y + lineHeight), cv::Scalar(0, 255, 0),2);
            
            // cv::line(image, cv::Point(rect.tl().x+rect.width, rect.tl().y), cv::Point(rect.tl().x+rect.width - lineHeight, rect.tl().y), cv::Scalar(0, 255, 0), 2);
            // cv::line(image, cv::Point(rect.tl().x+rect.width, rect.tl().y), cv::Point(rect.tl().x+rect.width , rect.tl().y + lineHeight), cv::Scalar(0, 255, 0), 2);

            // cv::line(image, cv::Point(rect.tl().x, rect.tl().y + rect.height), cv::Point(rect.tl().x, rect.tl().y + rect.height - lineHeight), cv::Scalar(0, 255, 0), 2);
            // cv::line(image, cv::Point(rect.tl().x, rect.tl().y + rect.height), cv::Point(rect.tl().x + lineHeight, rect.tl().y + rect.height ), cv::Scalar(0, 255, 0), 2);

            // cv::line(image, cv::Point(rect.tl().x+rect.width, rect.tl().y + rect.height), cv::Point(rect.tl().x+rect.width -lineHeight, rect.tl().y + rect.height), cv::Scalar(0, 255, 0), 2);
            // cv::line(image, cv::Point(rect.tl().x+rect.width, rect.tl().y + rect.height), cv::Point(rect.tl().x+rect.width , rect.tl().y + rect.height -lineHeight), cv::Scalar(0, 255, 0), 2);
            // //end


            cv::Rect roi(cv::Point(x, y), cv::Size(pw, ph));
            
            int w = 180;
            int h = 240;

            // int w = 100;
            // int h = 220;

            double fontScale = 0.8;
            int fontFace = cv::FONT_HERSHEY_DUPLEX;
            int thickness = 2;

            cv::Size textSize = cv::getTextSize(this->time, fontFace, fontScale, thickness, 0);
            int tx = (w - textSize.width)/2;
            int ty = 30;

            // cv::Mat vipIcon = cv::imread("vip.png");
            int wIcon = 30;
            int hIcon = 30;

            // cv::resize(vipIcon, vipIcon, cv::Size(wIcon, hIcon));

            cv::Rect roiIcon = cv::Rect(0,0, wIcon, hIcon);
            cv::Rect roiPortrait = cv::Rect(5, 5, wIcon, hIcon);


            cv::Rect validROI = roi & cv::Rect(0, 0, image.cols, image.rows);
            if (validROI.width > 0 && validROI.height > 0) {
                cv::Mat src = image(validROI);
                cv::resize(src, this->portrait, cv::Size(w, h));
            }
            cv::putText(this->portrait, this->time , cv::Point(tx + 1, ty + 1 + 200), fontFace, fontScale, cv::Scalar(0, 252, 0), 1);
            cv::putText(this->portrait, this->time , cv::Point(tx, ty + 200), fontFace, fontScale, cv::Scalar(0, 255, 0), 1);
            // cv::addWeighted(this->portrait(roiPortrait), 0.0, vipIcon(roiIcon), 1.0, 0.0, this->portrait(roiPortrait));
            // std::cout << this->portrait.size() << std::endl;
            // cv::imwrite("test.jpg", this->portrait);
            // std::string nameImage = "../facerecognize/" + this->time + "_" + std::to_string(this->frame) + ".jpg";
            // cv::imwrite(nameImage, this->portrait);
            
        }
        else {
            int pw = 180;
            int ph = 240;
            int cx = this->rect.x + this->rect.width / 2;
            int cy = this->rect.y + this->rect.height / 2;
            int x = cx - pw / 2;
            int y = cy - ph / 2;
            
            // check
            if (x < 0) {
                x = 0;
            }
            else if (x + pw > image.cols) {
                x = image.cols - pw;
            }
            
            if (y < 0) {
                y = 0;
            }
            else if (y + ph > image.rows) {
                y = image.rows - ph;
            }
            
            // add bouding box 
            // cv::rectangle(image, rect, cv::Scalar(0, 255, 0),4);
            // int lineHeight = 8;

            // cv::line(image, rect.tl(), cv::Point(rect.tl().x + lineHeight, rect.tl().y), cv::Scalar(0, 255, 0),2);
            // cv::line(image, rect.tl(), cv::Point(rect.tl().x , rect.tl().y + lineHeight), cv::Scalar(0, 255, 0),2);
            
            // cv::line(image, cv::Point(rect.tl().x+rect.width, rect.tl().y), cv::Point(rect.tl().x+rect.width - lineHeight, rect.tl().y), cv::Scalar(0, 255, 0), 2);
            // cv::line(image, cv::Point(rect.tl().x+rect.width, rect.tl().y), cv::Point(rect.tl().x+rect.width , rect.tl().y + lineHeight), cv::Scalar(0, 255, 0), 2);

            // cv::line(image, cv::Point(rect.tl().x, rect.tl().y + rect.height), cv::Point(rect.tl().x, rect.tl().y + rect.height - lineHeight), cv::Scalar(0, 255, 0), 2);
            // cv::line(image, cv::Point(rect.tl().x, rect.tl().y + rect.height), cv::Point(rect.tl().x + lineHeight, rect.tl().y + rect.height ), cv::Scalar(0, 255, 0), 2);

            // cv::line(image, cv::Point(rect.tl().x+rect.width, rect.tl().y + rect.height), cv::Point(rect.tl().x+rect.width -lineHeight, rect.tl().y + rect.height), cv::Scalar(0, 255, 0), 2);
            // cv::line(image, cv::Point(rect.tl().x+rect.width, rect.tl().y + rect.height), cv::Point(rect.tl().x+rect.width , rect.tl().y + rect.height -lineHeight), cv::Scalar(0, 255, 0), 2);
            //end


            cv::Rect roi(cv::Point(x, y), cv::Size(pw, ph));
            int w = 180;
            int h = 240;

            // int w = 100;
            // int h = 220;

            double fontScale = 0.8;
            int fontFace = cv::FONT_HERSHEY_DUPLEX;
            int thickness = 2;

            cv::Size textSize = cv::getTextSize(this->time, fontFace, fontScale, thickness, 0);
            int tx = (w - textSize.width)/2;
            int ty = 30;

            // cv::Mat vipIcon = cv::imread("vip.png");
            int wIcon = 30;
            int hIcon = 30;

            // cv::resize(vipIcon, vipIcon, cv::Size(wIcon, hIcon));

            cv::Rect roiIcon = cv::Rect(0,0, wIcon, hIcon);
            cv::Rect roiPortrait = cv::Rect(5, 5, wIcon, hIcon);


            cv::Rect validROI = roi & cv::Rect(0, 0, image.cols, image.rows);
            if (validROI.width > 0 && validROI.height > 0) {
                cv::Mat src = image(validROI);
                cv::resize(src, this->portrait, cv::Size(w, h));
            }
            cv::putText(this->portrait, this->time , cv::Point(tx + 1, ty + 1 + 200), fontFace, fontScale, cv::Scalar(0, 252, 0), 1);
            cv::putText(this->portrait, this->time , cv::Point(tx, ty + 200), fontFace, fontScale, cv::Scalar(0, 255, 0), 1);
            // cv::addWeighted(this->portrait(roiPortrait), 0.0, vipIcon(roiIcon), 1.0, 0.0, this->portrait(roiPortrait));
            // std::cout << this->portrait.size() << std::endl;
            // cv::imwrite("test.jpg", this->portrait);
            // std::string nameImage = "../facerecognize/" + this->time + "_" + std::to_string(this->frame) + ".jpg";
            // cv::imwrite(nameImage, this->portrait);
        }
    }
    else {
        this->portrait = image;
        int w = 180;
        int h = 240;
        double fontScale = 0.8;
        int fontFace = cv::FONT_HERSHEY_DUPLEX;
        int thickness = 2;

        cv::Size textSize = cv::getTextSize(this->time, fontFace, fontScale, thickness, 0);
        int tx = (w - textSize.width)/2;
        int ty = 30;
        cv::putText(this->portrait, this->time , cv::Point(tx + 1, ty + 1 + 200), fontFace, fontScale, cv::Scalar(0, 252, 0), 1);
        cv::putText(this->portrait, this->time , cv::Point(tx, ty + 200), fontFace, fontScale, cv::Scalar(0, 255, 0), 1);


    }
}