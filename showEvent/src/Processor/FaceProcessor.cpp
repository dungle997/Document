//
//  FaceProcessor.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "FaceProcessor.hpp"

FaceProcessor::FaceProcessor(int cameraId, DisplayBoard *displayBoard, int index, ProfileManager *profileManager, EventManager *eventManager)
{
    this->cameraId = cameraId;
    this->displayBoard = displayBoard;
    this->index = index;
    this->profileManager = profileManager;
    this->eventManager = eventManager;
}

FaceProcessor::~FaceProcessor()
{
}

void FaceProcessor::process(Mat &frame) {
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

    std::string type ;
    if (config.language == "VN") {
        type = "NHẬN DIỆN KHUÔN MẶT";
    }
    else {
        type = "FACE RECOGNITION";
    }

    cv::Size textName = ft2->getTextSize(type, fontHeight, thinkness, &baseline);
    ft2->putText(frame, type, cv::Point((frame.cols - textName.width) /2, 40 + textName.height), fontHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);
    ft2->putText(frame, type, cv::Point((frame.cols - textName.width) /2 + 1, 41 + textName.height), fontHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);
    
    displayFaceEvent(frame);
    displayUnknownFaceEvent(frame);

     //add logo 
    // cv::Mat icon = cv::imread(AIVIEW_ICON_PATH, cv::IMREAD_ANYCOLOR);
    // int width = 400;
    // int height = 100;
    // cv::Rect roiIcon(0, 0, width, height);
    // cv::Rect roiFrame(10, 1080 - 10 -height, width, height);

    // cv::resize(icon, icon, cv::Size(width, height));

    // cv::addWeighted(frame(roiFrame), 0.6, icon(roiIcon) , 0.4 , 0.0 ,frame(roiFrame));//de lam mo anh khi chen icon vao
    this->displayBoard->put(frame, this->index);
}

void FaceProcessor::displayFaceEvent(Mat &frame)
{
    int viewIndex = 0;
    int countText = 0;
    int fontHeight = 20;
    int thinkness = -1;
    int baseline = 0;
    int linestype = cv::LINE_AA;

    cv::Ptr<cv::freetype::FreeType2> ft2;
    ft2 = cv::freetype::createFreeType2();
    ft2->loadFontData(FONT_PATH, 0);
    for (int index = 0; index < this->eventManager->faceEvents.size(); index++)
    {
        FaceEvent *event = this->eventManager->faceEvents[index];
        if (event->cameraId == this->cameraId && viewIndex < 4)
        {
            // Profile *profile = this->profileManager->profiles[event->profileId]; // dung profile
            // if (profile != nullptr && event->portrait.cols != 0) {

            if (event->portrait.cols != 0) {  // ko dung profile 
                int w = event->portrait.cols;
                int h = event->portrait.rows;
                Rect roi(24, 24 + (24 + h) * viewIndex, w, h);
                Mat dst = frame(roi);
                event->portrait.copyTo(dst);
                //add time in face edit by TruongNXd
                double fontScale = 0.6;
                int fontFace = cv::FONT_HERSHEY_DUPLEX;
                int thickness = 1;
                int baseLine;

                cv::Size textSize = getTextSize(event->time, fontFace, fontScale, thickness, 0);
                

                int tx = (w - textSize.width / 2) - 70;
                int ty = 24 + (24 + h) * viewIndex + h - 10;
                //end code

                // const char* text = profile->name.c_str();     
                // cv::Size ts = ft2->getTextSize(profile->name.c_str(), fontHeight, thinkness, &baseline);
                const char* text = event->profileId.c_str();
                cv::Size ts = ft2->getTextSize(event->profileId.c_str(), fontHeight, thinkness, &baseline);
                
                int txProfile = (w - ts.width / 2) - 70;
                int tyProfile = 20 + 24 + (24 + h) * viewIndex;
                
                ft2->putText(frame, text,cv::Point(txProfile + 1, tyProfile + 1), fontHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);
                viewIndex++;
            }
        }
    }
}

void FaceProcessor::displayUnknownFaceEvent(Mat &frame)
{
    int viewIndex = 0;
    for (int index = 0; index < this->eventManager->unknownFaceEvents.size(); index++)
    {
        UnknownFaceEvent *event = this->eventManager->unknownFaceEvents[index];
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
