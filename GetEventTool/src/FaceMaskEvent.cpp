//
//  FaceMaskEvent.cpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 05/08/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//
#include "FaceMaskEvent.hpp"

FaceMaskEvent::FaceMaskEvent(int cameraId, std::vector<cv::Rect>& rect, std::string time, int frame, std::string ipcamera, std::vector<int> fmask) {
    this->cameraId = cameraId;
    this->rect = rect;
    this->ipcamera = ipcamera;
    this->time = time;
    this->frame = frame;
    this->fmask = fmask;
}

FaceMaskEvent::~FaceMaskEvent() {
}

void FaceMaskEvent::update (const cv::Mat& image) {
    this->image = image;
    // cv::Size textTismeSize = cv::getTextSize(this->time, cv::FONT_HERSHEY_TRIPLEX, 2, 3, 0);
    // cv::putText(this->image, this->time, cv::Point(this->image.cols - textTimeSize.width - 30, 40 + textTimeSize.height), cv::FONT_HERSHEY_TRIPLEX, 2, cv::Scalar(0, 67, 255), 3);
    // Draw box
    // for (auto box: this->rect) {
    //     cv::rectangle(this->image, box, cv::Scalar(0, 255, 0), 4);
    // }
	//for (auto box: this->rect) {
    //    cv::rectangle(this->image, box, cv::Scalar(0, 0, 0), 4);
    //}
    std::string name ="";
    for (auto Fmask : fmask){
        name = name + std::to_string(Fmask) + "_";
    }
    if (!image.empty()){
    std::string nameImage = "../Event/" + this->ipcamera + "/facemask/" + this->time + "_" + name +"_" + std::to_string(this->frame) + ".jpg";
    cv::imwrite(nameImage,image);
    }
    // calc portrait size
    // int fs = this->rect.width > this->rect.height ? this->rect.width : this->rect.height;
    
    // int pw = 2 * fs;
    // int ph = pw * 4 / 3;
    // int cx = this->rect.x + this->rect.width / 2;
    // int cy = this->rect.y + this->rect.height / 2;
    // int x = cx - pw / 2;
    // int y = cy - pw / 2;
    
    // // check
    // if (x < 0) {
    //     x = 0;
    // }
    // else if (x + pw > image.cols) {
    //     x = image.cols - pw;
    // }
    
    // if (y < 0) {
    //     y = 0;
    // }
    // else if (y + ph > image.rows) {
    //     y = image.rows - ph;
    // }
    
    // // add bouding box 
    // // cv::rectangle(image, rect, cv::Scalar(0, 255, 0),4);
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
    

    // cv::Rect roi(cv::Point(x, y), cv::Size(pw, ph));
    
    // int w = 180;
    // int h = 240;

    // //font Have Face Mask text
    // double fontScale = 0.6;
    // int fontFace = cv::FONT_HERSHEY_DUPLEX;
    // int thickness = 1;
    // cv::Size textSize = cv::getTextSize(this->time, fontFace, fontScale, thickness, 0);
    // int fontHeight = 20;
    // int thinkness = -1;
    // int baseline = 0;
    // int linestype = cv::LINE_AA;

    // cv::Ptr<cv::freetype::FreeType2> ft2;
    // ft2 = cv::freetype::createFreeType2();
    // ft2->loadFontData("demofont.ttf", 0);

    // std::string type;
    // if (config.language == "VN") {
    //     type = "Có khẩu trang";
    // }
    // else{
    //     type = "Face Mask";
    // }
    
    // cv::Size textName = ft2->getTextSize(type, fontHeight, thinkness, &baseline);
    
    // int tx = (w - textSize.width)/2;
    // int ty = 30;

    // cv::Rect validROI = roi & cv::Rect(0, 0, image.cols, image.rows);
    // if (validROI.width > 0 && validROI.height > 0) {
    //     cv::Mat src = image(validROI);
    //     cv::resize(src, this->portrait, cv::Size(w, h));
    //     ft2->putText(this->portrait, type, cv::Point((w - textName.width) /2, 20), fontHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);

    //     //add time in unknown face
    //     cv::putText(this->portrait, this->time , cv::Point(tx +1 , ty + +200 + 1 ), fontFace, fontScale, cv::Scalar(0, 253, 0), 1);
    //     cv::putText(this->portrait, this->time , cv::Point(tx  , ty +200), fontFace, fontScale, cv::Scalar(0, 255, 0), 1);
    // }

}
