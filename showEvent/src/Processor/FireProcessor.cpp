//
//  FireProcessor.cpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 19/08/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.

#include "FireProcessor.hpp"

FireProcessor::FireProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager) {
    this->cameraId = cameraId;
    this->displayBoard = displayBoard;
    this->index = index;
    this->eventManager = eventManager;
}

FireProcessor::~FireProcessor() {
    
}

void FireProcessor::process(Mat& frame) {
    if (frame.size() != cv::Size( 1920, 1080)) {
        cv::resize(frame, frame , cv::Size(1920, 1080));
    }
    int h = 480;
    int w = 640;
    
    FireEvent* lastEvent = NULL;
    
    int viewIndex = 0;
    for (int index = 0; index < this->eventManager->fireEvents.size(); index++) {
        FireEvent* event = this->eventManager->fireEvents[index];
        if (event->cameraId == this->cameraId && !event->image.empty()) {
            if (lastEvent == NULL) {
                lastEvent = event;
            }
            
            if (viewIndex < 1) {
                cv::Rect roi(frame.cols - w - 24, 24 + (24 + h) * viewIndex, w, h);
                Mat dst = frame(roi);
                cv::resize(event->image, dst, cv::Size(w, h));
                viewIndex++;
            }
        }
    }
    
    //write model name


    std::string type ;
    if (config.language == "VN") {
        type = "PHÁT HIỆN ĐÁM CHÁY ";
    }
    else {
        type = "FIRE DETECTION";
    }

    int fontHeight = 60;
    int thinkness = -1;
    int baseline = 0;
    int linestype = cv::LINE_AA;

    cv::Ptr<cv::freetype::FreeType2> ft2;
    ft2 = cv::freetype::createFreeType2();
    ft2->loadFontData(FONT_PATH, 0);
    cv::Size textName = ft2->getTextSize(type, fontHeight, thinkness, &baseline);
    ft2->putText(frame, type, cv::Point((frame.cols - textName.width) /2, 40 + textName.height), fontHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);
    ft2->putText(frame, type, cv::Point((frame.cols - textName.width) /2 + 1, 41 + textName.height), fontHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);
    
    //add logo 
    cv::Mat icon = cv::imread(AIVIEW_ICON_PATH);
    int width = 400;
    int height = 100;
    cv::Rect roiIcon(0, 0, width, height);
    cv::Rect roiFrame(10, 1080 - 10 -height, width, height);

    cv::resize(icon, icon, cv::Size(width, height));

    cv::addWeighted(frame(roiFrame), 0.6, icon(roiIcon) , 0.4, 0.0 ,frame(roiFrame));
    this->displayBoard->put(frame, this->index);
}

