//
//  UnknownFaceEvent.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 18/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "UnknownFaceEvent.hpp"

UnknownFaceEvent::UnknownFaceEvent(int cameraId, const cv::Rect& rect, const std::string& time, std::string frame) {
    this->cameraId = cameraId;
    this->rect = rect;
    this->time = time;
    this->frame = frame;
}

UnknownFaceEvent::~UnknownFaceEvent() {
    
}

void UnknownFaceEvent::update(const cv::Mat& image) {
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

            cv::Rect validROI = roi & cv::Rect(0, 0, image.cols, image.rows);
            if (validROI.width > 0 && validROI.height > 0) {
                cv::Mat src = image(validROI);
                cv::resize(src, this->portrait, cv::Size(w, h));
            }
            // cv::putText(this->portrait, this->time , cv::Point(tx + 1, ty + 1 + 200), fontFace, fontScale, cv::Scalar(0, 252, 0), 1);
            // cv::putText(this->portrait, this->time , cv::Point(tx, ty + 200), fontFace, fontScale, cv::Scalar(0, 255, 0), 1);
            // cv::addWeighted(this->portrait(roiPortrait), 0.0, vipIcon(roiIcon), 1.0, 0.0, this->portrait(roiPortrait));
            // std::cout << this->portrait.size() << std::endl;
            // cv::imwrite("test.jpg", this->portrait);
            // std::string nameImage = "../facerecognize/" + this->time + "_" + std::to_string(this->frame) + ".jpg";
            // cv::imwrite(nameImage, this->portrait);
            double fontScale = 0.8;
            int fontFace = cv::FONT_HERSHEY_DUPLEX;
            int thickness = 2;
            // cv::Size textGuest = cv::getTextSize("Guest", fontFace, fontScale, thickness, 0);

            int fontHeight = 20;
            int thinkness = -1;
            int baseline = 0;
            int linestype = cv::LINE_AA;
            cv::Size textTime = cv::getTextSize(this->time, fontFace, fontScale, thickness, 0);

            int tx = (w - textTime.width)/2;
            int ty = 30;
            cv::Ptr<cv::freetype::FreeType2> ft2;
            ft2 = cv::freetype::createFreeType2();
            ft2->loadFontData(FONT_PATH, 0);

            std::string type;

            if (config.language == "VN") {
                type = "Khách";
            }
            else {
                type = "Guest";
            }

            cv::Size textName = ft2->getTextSize(type, fontHeight, thinkness, &baseline);

            // int tx = (w - textGuest.width)/2;
            // int ty = 30;
            ft2->putText(this->portrait, type, cv::Point((w - textName.width) /2, 20), fontHeight ,cv::Scalar(0, 67, 255), thinkness, linestype, true);
            tx = (w - textTime.width)/2;
            //add time in unknown face
            cv::putText(this->portrait, this->time , cv::Point(tx + 1, ty + 1 + 200), fontFace, fontScale, cv::Scalar(0, 67, 255), 1);
            cv::putText(this->portrait, this->time , cv::Point(tx, ty + 200), fontFace, fontScale, cv::Scalar(0, 70, 255), 1);
            // std::string nameImage = "../Guest/" + this->time + "_" + std::to_string(this->frame) + ".jpg";
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

            // cv::Rect roiIcon = cv::Rect(0,0, wIcon, hIcon);
            // cv::Rect roiPortrait = cv::Rect(5, 5, wIcon, hIcon);


            cv::Rect validROI = roi & cv::Rect(0, 0, image.cols, image.rows);
            if (validROI.width > 0 && validROI.height > 0) {
                cv::Mat src = image(validROI);
                cv::resize(src, this->portrait, cv::Size(w, h));
            }
            double fontScale = 0.8;
            int fontFace = cv::FONT_HERSHEY_DUPLEX;
            int thickness = 2;
            // cv::Size textGuest = cv::getTextSize("Guest", fontFace, fontScale, thickness, 0);

            int fontHeight = 20;
            int thinkness = -1;
            int baseline = 0;
            int linestype = cv::LINE_AA;
            cv::Size textTime = cv::getTextSize(this->time, fontFace, fontScale, thickness, 0);

            int tx = (w - textTime.width)/2;
            int ty = 30;
            cv::Ptr<cv::freetype::FreeType2> ft2;
            ft2 = cv::freetype::createFreeType2();
            ft2->loadFontData(FONT_PATH, 0);

            std::string type;

            if (config.language == "VN") {
                type = "Khách";
            }
            else {
                type = "Guest";
            }

            cv::Size textName = ft2->getTextSize(type, fontHeight, thinkness, &baseline);

            // int tx = (w - textGuest.width)/2;
            // int ty = 30;
            ft2->putText(this->portrait, type, cv::Point((w - textName.width) /2, 20), fontHeight ,cv::Scalar(0, 67, 255), thinkness, linestype, true);
            tx = (w - textTime.width)/2;
            //add time in unknown face
            cv::putText(this->portrait, this->time , cv::Point(tx + 1, ty + 1 + 200), fontFace, fontScale, cv::Scalar(0, 67, 255), 1);
            cv::putText(this->portrait, this->time , cv::Point(tx, ty + 200), fontFace, fontScale, cv::Scalar(0, 70, 255), 1);
            // std::string nameImage = "../Guest/" + this->time + "_" + std::to_string(this->frame) + ".jpg";
            // cv::imwrite(nameImage, this->portrait);
                
            
        }
    }
    else{
        this->portrait = image; 
        if (image.size() != cv::Size(180, 240)) {
            cv::resize(image, image , cv::Size(180, 240));
        }
            std::cout << "image.rows in unknown face event" << image.rows << std::endl;
            std::cout << "image.cols in unknown face event" << image.cols << std::endl;
            int w = 180;
            int h = 240;
            double fontScale = 0.8;
            int fontFace = cv::FONT_HERSHEY_DUPLEX;
            int thickness = 2;
            // cv::Size textGuest = cv::getTextSize("Guest", fontFace, fontScale, thickness, 0);

            int fontHeight = 20;
            int thinkness = -1;
            int baseline = 0;
            int linestype = cv::LINE_AA;
            cv::Size textTime = cv::getTextSize(this->time, fontFace, fontScale, thickness, 0);

            int tx = (w - textTime.width)/2;
            int ty = 30;
            cv::Ptr<cv::freetype::FreeType2> ft2;
            ft2 = cv::freetype::createFreeType2();
            ft2->loadFontData(FONT_PATH, 0);

            std::string type;

            if (config.language == "VN") {
                type = "Khách";
            }
            else {
                type = "Guest";
            }

            cv::Size textName = ft2->getTextSize(type, fontHeight, thinkness, &baseline);

            // int tx = (w - textGuest.width)/2;
            // int ty = 30;
                ft2->putText(this->portrait, type, cv::Point((w - textName.width) /2, 20), fontHeight ,cv::Scalar(0, 67, 255), thinkness, linestype, true);
                tx = (w - textTime.width)/2;
                //add time in unknown face
                cv::putText(this->portrait, this->time , cv::Point(tx + 1, ty + 1 + 200), fontFace, fontScale, cv::Scalar(0, 67, 255), 1);
                cv::putText(this->portrait, this->time , cv::Point(tx, ty + 200), fontFace, fontScale, cv::Scalar(0, 70, 255), 1);
                // std::string nameImage = "../Guest/" + this->time + "_" + std::to_string(this->frame) + ".jpg";
                // cv::imwrite(nameImage, this->portrait);
    }
        
}
    