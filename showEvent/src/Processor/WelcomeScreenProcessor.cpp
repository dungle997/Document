//
//  WelcomeSceenProcessor.cpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 21/12/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#include "WelcomeSceenProcessor.hpp"

WelcomeSceenProcessor::WelcomeSceenProcessor(int cameraId, DisplayBoard* displayBoard, int index, ProfileManager* profileManager, EventManager* eventManager) {
    this->cameraId = cameraId;
    this->displayBoard = displayBoard;
    this->index = index;
    this->profileManager = profileManager;
    this->eventManager = eventManager;
    this->ft2 = cv::freetype::createFreeType2();
    this->ft2->loadFontData(FONT_PATH, 0);
}

WelcomeSceenProcessor::~WelcomeSceenProcessor() {

}

void WelcomeSceenProcessor::process (cv::Mat &frame){
    if (frame.size() != cv::Size( 1920, 1080)) {
        cv::resize(frame, frame , cv::Size(1920, 1080));
    }
    
    //add logo 
    cv::Mat icon = cv::imread(AIVIEW_ICON_PATH, cv::IMREAD_ANYCOLOR);
    int width = 400;
    int height = 100;
    cv::Rect roiIcon(0, 0, width, height);
    cv::Rect roiFrame(30, 30, width, height);

    cv::resize(icon, icon, cv::Size(width, height));

    cv::addWeighted(frame(roiFrame), 0.4, icon(roiIcon) , 0.6, 0.0 ,frame(roiFrame));

    displayProfileImage(frame);
    displayFaceEvent(frame);
    this->displayBoard->put(frame, this->index);
}

void WelcomeSceenProcessor::displayProfileImage (cv::Mat& frame) {
    int faceSize = this->eventManager->faceEvents.size();
    if (faceSize > 0) {
        FaceEvent* event = this->eventManager->faceEvents[0];
        Profile* profile = this->profileManager->profiles[event->profileId];
        if (event->cameraId == this->cameraId) {
            if (profile != nullptr && !profile->portrait.empty()) {
                int w = profile->portrait.cols;
                int h = profile->portrait.rows;
                
                cv::Rect roi(frame.cols - 30 - w, 30, w, h);

                Mat dst = frame(roi);
                profile->portrait.copyTo(dst);

                double fontScale = 0.8;
                int fontFace = cv::FONT_HERSHEY_DUPLEX;
                int thickness = 1;

                cv::Size textSize = getTextSize(event->time, fontFace, fontScale, thickness, 0);
                

                int tx = frame.cols - (w - textSize.width /2);
                int ty = 30 + h - 10;
                cv::putText(frame, event->time, cv::Point(tx + 1, ty + 1), fontFace, fontScale, cv::Scalar(0, 252, 0), thickness);
                cv::putText(frame, event->time, cv::Point(tx, ty), fontFace, fontScale, cv::Scalar(0, 255, 0), thickness);

                // add welcome 
                std::string welcomeText;
                if (config.language == "VN") {
                    welcomeText = "CHÀO MỪNG";
                }
                else {
                    welcomeText = "WELCOME"; 
                }
                
                int fontWelcomeHeight = 40;
                int fontNameHeight = 60;
                int thinkness = -1;
                int baseline = 0;
                int linestype = cv::LINE_AA;

                cv::Size welcomeSize = this->ft2->getTextSize(welcomeText, fontWelcomeHeight, thinkness, &baseline);
                cv::Size nameSize = this->ft2->getTextSize(profile->name, fontNameHeight, thinkness, &baseline);
                cv::Size postionSize = this->ft2->getTextSize(profile->position, fontWelcomeHeight, thinkness, &baseline);

                w = (nameSize.width > welcomeSize.width) ? (nameSize.width + 20) : (welcomeSize.width + 20) ;
                w = (w > postionSize.width) ? w : (postionSize.width + 20);
                h = welcomeSize.height + 20; 


                cv::Mat matText(h, w, CV_8UC3, cv::Scalar(0, 0, 0));

                //add welcome
                tx =  matText.cols/2 - welcomeSize.width / 2;
                ty =  matText.rows - welcomeSize.height / 2 + 5;             
                ft2->putText(matText, welcomeText, cv::Point(tx, ty), fontWelcomeHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);

                cv::Rect roiImg(0, 0, w, h);
                cv::Rect roiText(frame.cols/2 - w/2, 50 , w, h);
                cv::addWeighted(frame(roiText), 0.3, matText(roiImg), 0.7, 0.0, frame(roiText));

                // add postion
                h = postionSize.height + 20;
                cv::Mat matPostion(h, w, CV_8UC3, cv::Scalar(0, 0, 0));
                tx =  matPostion.cols/2 - postionSize.width / 2;
                ty =  matPostion.rows - postionSize.height / 2 + 5;
                roiImg = cv::Rect(0, 0, w, h);
                roiText = cv::Rect(frame.cols/2 - w/2, roiText.br().y , w, h);
                ft2->putText(matPostion, profile->position, cv::Point(tx, ty), fontWelcomeHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);
                cv::addWeighted(frame(roiText), 0.3, matPostion(roiImg), 0.7, 0.0, frame(roiText));

                // add name 
                h = nameSize.height + 20;
                cv::Mat matName(h, w, CV_8UC3, cv::Scalar(0, 0, 0));
                tx =  matName.cols/2 - nameSize.width / 2;
                ty = matName.rows - nameSize.height / 2 + 11;
                ft2->putText(matName, profile->name, cv::Point(tx, ty), fontNameHeight ,cv::Scalar(0, 255, 0), thinkness, linestype, true);
                cv::Rect roiNameImg(0, 0, w, h);
                cv::Rect roiName(frame.cols/2 - w/2, roiText.br().y , w, h);
                cv::addWeighted(frame(roiName), 0.3, matName(roiNameImg), 0.7, 0.0, frame(roiName));
            }
        }
    }
}

void WelcomeSceenProcessor::displayFaceEvent(cv::Mat& frame) {
    int viewIndex = 0;
    for (int index = 0; index < this->eventManager->faceEvents.size(); index++) {
        FaceEvent *event = this->eventManager->faceEvents[index];
        if (event->cameraId == this->cameraId && viewIndex < 9) {
            Profile *profile = this->profileManager->profiles[event->profileId];
            if (profile != nullptr && event->portrait.cols != 0) {
            // if (profile != nullptr) {
                int w = profile->mini.cols;
                int h = profile->mini.rows;
                Rect roi(15 + (15 + w) * viewIndex, frame.rows - h - 15, w, h);
                Mat dst = frame(roi);
                profile->mini.copyTo(dst);
                //add time in face edit by TruongNXd
                double fontScale = 0.6;
                int fontFace = cv::FONT_HERSHEY_DUPLEX;
                int thickness = 1;

                cv::Size textSize = getTextSize(event->time, fontFace, fontScale, thickness, 0);

                int tx =  (15 + w - textSize.width) /2 +  (15 + w) * viewIndex;
                int ty = frame.rows - 25;
                //end code

                cv::putText(frame, event->time, cv::Point(tx + 1, ty + 1), fontFace, fontScale, cv::Scalar(0, 252, 0), thickness);
                cv::putText(frame, event->time, cv::Point(tx, ty), fontFace, fontScale, cv::Scalar(0, 255, 0), thickness);
                
                viewIndex++;
            }
        }
    }
}