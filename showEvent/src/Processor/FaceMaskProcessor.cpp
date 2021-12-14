//
//  FaceMaskProcessor.cpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 05/08/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#include "FaceMaskProcessor.hpp"

FaceMaskProcessor::FaceMaskProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager) {
    this->cameraId = cameraId;
    this->displayBoard = displayBoard;
    this->index = index;
    this->eventManager = eventManager;

    
}

FaceMaskProcessor::~FaceMaskProcessor() {
}

void FaceMaskProcessor::process(Mat &frame) {
    if (frame.size() != cv::Size( 1920, 1080)) {
        cv::resize(frame, frame , cv::Size(1920, 1080));
    }
    
    int fontHeight = 60;
    int thinkness = -1;
    int baseline = 0;
    int linestype = cv::LINE_AA;

    cv::Ptr<cv::freetype::FreeType2> ft2;
    ft2 = cv::freetype::createFreeType2();
    ft2->loadFontData(FONT_PATH, 0);
    std::string type;
    if (config.language == "VN") {
        type = "KIỂM TRA ĐEO KHẨU TRANG";
    }
    else {
        type = "FACE MASK DETECTION";
    }
    
    cv::Size textName = ft2->getTextSize(type, fontHeight, thinkness, &baseline);
    ft2->putText(frame, type, cv::Point((frame.cols - textName.width) /2, 40 + textName.height), fontHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);
    ft2->putText(frame, type, cv::Point((frame.cols - textName.width) /2 + 1, 41 + textName.height), fontHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);
    
    displayFaceMaskEvent(frame);
    displayNoFaceMaskEvent(frame);

    //add logo 
    cv::Mat icon = cv::imread(AIVIEW_ICON_PATH, cv::IMREAD_ANYCOLOR);
    int width = 400;
    int height = 100;
    cv::Rect roiIcon(0, 0, width, height);
    cv::Rect roiFrame(10, 1080 - 10 -height, width, height);

    cv::resize(icon, icon, cv::Size(width, height));

    cv::addWeighted(frame(roiFrame), 0.6, icon(roiIcon) , 0.4 , 0.0 ,frame(roiFrame));
    this->displayBoard->put(frame, this->index);
}

void FaceMaskProcessor::displayFaceMaskEvent (cv::Mat& frame) {
    int viewIndex = 0;
    for (int index = 0; index < this->eventManager->faceMaskEvents.size(); index++)
    {
        FaceMaskEvent *event = this->eventManager->faceMaskEvents[index];
        if (event->cameraId == this->cameraId && viewIndex < 4 )
        {
            cv::Mat portrait = event->portrait;

            if (!portrait.empty())
            {
                int w = portrait.cols;
                int h = portrait.rows;
                Rect roi(24, 24 + (24 + h) * viewIndex, w, h);
                Mat dst = frame(roi);
                portrait.copyTo(dst);
                viewIndex++;
            }
        }
    }
}

void FaceMaskProcessor::displayNoFaceMaskEvent (cv::Mat& frame) {
    int viewIndex = 0;
    for (int index = 0; index < this->eventManager->noFaceMaskEvents.size(); index++)
    {
        NoFaceMaskEvent *event = this->eventManager->noFaceMaskEvents[index];
        if (event->cameraId == this->cameraId && viewIndex < 4)
        {
            cv::Mat portrait = event->portrait;

            if (!portrait.empty())
            {
                int w = portrait.cols;
                int h = portrait.rows;
                Rect roi(frame.cols - w - 24, 24 + (24 + h) * viewIndex, w, h);
                Mat dst = frame(roi);
                portrait.copyTo(dst);
                viewIndex++;
            }
        }
    }
}
