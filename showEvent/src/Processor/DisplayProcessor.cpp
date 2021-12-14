//
//  DisplayProcessor.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 14/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "DisplayProcessor.hpp"

DisplayProcessor::DisplayProcessor(DisplayBoard* displayBoard, int index) {
    this->displayBoard = displayBoard;
    this->index = index;
}

DisplayProcessor::~DisplayProcessor() {
    
}

void DisplayProcessor::process(Mat& frame) {
    if (frame.size() != cv::Size( 1920, 1080)) {
        cv::resize(frame, frame , cv::Size(1920, 1080));
    }
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
