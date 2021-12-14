//
//  LicenseProcessor.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 21/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "LicenseProcessor.hpp"

LicenseProcessor::LicenseProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager) {
    this->cameraId = cameraId;
    this->displayBoard = displayBoard;
    this->index = index;
    this->eventManager = eventManager;
}

LicenseProcessor::~LicenseProcessor() {
    
}

void LicenseProcessor::process(Mat& frame) {

    if (frame.size() != cv::Size(1920, 1080)) {
        cv::resize(frame, frame , cv::Size(1920, 1080));
    }
    cv::Mat frame1;
    int widthFrame = 900;
    int heightFrame = 1600;
    cv::resize(frame, frame1, cv::Size(heightFrame,widthFrame));

    // process license display 
    int h = 120;
    // int w = 427;
    int w = 320;

    LicenseEvent* lastEvent = NULL;
   

    //resize main frame 
    
    cv::Rect roiMainImg(0, 0, heightFrame, widthFrame);
    cv::Rect roiMainImgvsFrame(0, 90 ,heightFrame, widthFrame);
    cv::addWeighted(frame(roiMainImgvsFrame), 0.0, frame1(roiMainImg), 1, 0.0, frame(roiMainImgvsFrame));
    //
    // add black image to main frame
    cv::Mat whiteImg(90, 1600, CV_8UC3, cv::Scalar(50,205,50)); // 0 77 255 
    // cv::Mat whiteImg(90, 1600, CV_8UC3, cv::Scalar(0,77,255));
    // cv::Mat blackImg(1080, 320, CV_8UC3,cv::Scalar(0,0,0));
    cv::Mat blackImg(1080, 320, CV_8UC3,cv::Scalar(192,192,192));
    cv::Rect roiBlackImg(0, 0, 320, 1080);
    // cv::Rect roiPositionBlackImg1(0 , 0, 320, 1080);
    cv::Rect roiPositionBlackImg2(1920 - 320 , 0, 320, 1080);
    cv::Rect roiWhiteImg(0, 0, 1600, 90);
    cv::Rect roiPositionWhiteImg(0, 0, 1600, 90);
    cv::Rect roiPositionWhiteImg1(0, 1080 - 90, 1600, 90);
    // cv::addWeighted(frame(roiPositionBlackImg1), 0.0, blackImg(roiBlackImg), 1, 0.0, frame(roiPositionBlackImg1));
    cv::addWeighted(frame(roiPositionBlackImg2), 0.0, blackImg(roiBlackImg), 1, 0.0, frame(roiPositionBlackImg2));
    cv::addWeighted(frame(roiPositionWhiteImg), 0.0, whiteImg(roiWhiteImg), 1, 0.0, frame(roiPositionWhiteImg));
    cv::addWeighted(frame(roiPositionWhiteImg1), 0.0, whiteImg(roiWhiteImg), 1, 0.0, frame(roiPositionWhiteImg1));
    //
    int viewIndex = 0;
    // std::cout << "size of license event = " << this->eventManager->licenseEvents.size() << std::endl;
    // for (int index = 0; index < this->eventManager->licenseEvents.size(); index++) {
    // std::cout << "heheheh" << std::endl;
    static int countShow = 0;
    if(!this->eventManager->licenseEvents.empty()){
        for (int index = this->eventManager->licenseEvents.size() - 1; index > -1; index--) {
            // std::cout << "heheheh1111" << std::endl;
            // std::cout << "index = " << index << std::endl;
            LicenseEvent* event = this->eventManager->licenseEvents[index];
            if (event->cameraId == this->cameraId && !event->image.empty()) {
                if (lastEvent == NULL) {
                    lastEvent = event;
                }

                if (viewIndex < 6) {
                    cv::Rect roiImg(0, 0, w, h);
                    // cv::Rect roiImgvsFrame(0, (h + 20)*viewIndex ,w, h);
                    cv::Rect roiImgvsFrame(frame.cols - w, (h + h/2)*viewIndex ,w, h);
                    cv::Rect roiText(frame.cols - w, h + (h + h/2)*viewIndex, w, h/2);
                    //addWeighted license image
                    cv::resize(event->image, event->image, cv::Size(w, h));
                    cv::addWeighted(frame(roiImgvsFrame), 0.0, event->image(roiImg), 1, 0.0, frame(roiImgvsFrame));

                    //addWeight license text
                    cv::Mat matText(h/2, w, CV_8UC3, cv::Scalar(0, 0, 0));
                    cv::Rect roiEventImg(0, 0, w, h/2);

                    // Display text
                    double fontScale = 1;
                    int baseLine = 0;
                    int fontFace = cv::FONT_HERSHEY_DUPLEX;
                    // int fontFace = cv::FONT_HERSHEY_SIMPLEX;
                    int thickness = 2;
                    const char* text = event->number.c_str();

                    // cv::Size ts = cv::getTextSize(text, fontFace, fontScale, thickness, &baseLine);
                    
                    cv::Ptr<cv::freetype::FreeType2> ft3;
                    ft3 = cv::freetype::createFreeType2();
                    ft3->loadFontData(FONT_PATH, 0);
                    int fontHeight = 32;
                    int fontTimeHeight = 22;
                    int thinkness = -1;
                    int baseline = 0;
                    int linestype = cv::LINE_AA;
                    cv::Size ts = ft3->getTextSize(text, fontHeight, thinkness, &baseline);
                    int tx = (matText.cols - ts.width)/2;

                    int ty = (matText.rows - ts.height)/2 + 10;
                    ft3->putText(matText, text, cv::Point(tx, ty), fontHeight, cv::Scalar(0, 67, 255), thinkness, linestype, true);
                    // ft3->putText(matText, text, cv::Point(tx+1, ty+1), fontFace, fontScale, cv::Scalar(0, 70, 255), thickness);

                    double fontScaleTime = 0.7;
                    int thicknessTime = 1;

                    // cv::Size textSize = getTextSize(event->time, fontFace, fontScaleTime, thicknessTime, 0);
                    cv::Size textSize = ft3->getTextSize(event->time, fontTimeHeight, thinkness, &baseline);

                    int txTime = (matText.cols - textSize.width)/2;
                    int tyTime = matText.rows -10;
                    // ft2->putText(frame, type, cv::Point((frame.cols - textName.width) /2 - 160,  10 + textName.height), fontHeight ,cv::Scalar(255, 255, 255), thinkness, linestype, true);
                    ft3->putText(matText, event->time, cv::Point(txTime, tyTime), fontTimeHeight, cv::Scalar(0, 255, 0), thinkness, linestype, true);
                    cv::addWeighted(frame(roiText), 0.3, matText(roiEventImg), 0.7, 0.0, frame(roiText));
                    // std::string nameImage = "../datalicense/" + event->time + "_" + event->frame + "_" + event->number + ".jpg";
                    // cv::imwrite(nameImage, frame);
                    // cv::imwrite("screen.jpg",frame);
                    viewIndex ++;
                    // usleep(1000);
                    // if (this->eventManager->licenseEvents.size() > 6){
                    //     for (size_t i = 0; i < 1; i++){
                    //     LicenseEvent* last = this->eventManager->licenseEvents.back();
                    //     this->eventManager->licenseEvents.pop_back();
                    //     delete last;
                    //     }    
                    // }
                }
            }
        } 
        countShow++;
        if (countShow == 40){
            if (this->eventManager->licenseEvents.size() > 6){
                for (size_t i = 0; i < 6; i++){
                LicenseEvent* last = this->eventManager->licenseEvents.back();
                this->eventManager->licenseEvents.pop_back();
                delete last;
                }    
            }
        countShow = 0;
        }
    }   
    // put title 
    int fontHeight = 60;
    int thinkness = -1;
    int baseline = 0;
    int linestype = cv::LINE_AA;

    cv::Ptr<cv::freetype::FreeType2> ft2;
    ft2 = cv::freetype::createFreeType2();
    ft2->loadFontData(FONT_PATH, 0);
    std::string type;
    if (config.language == "VN") {
        type = "NHẬN DIỆN BIỂN SỐ";
    }
    else {
        type = "LICENSE PLATE RECOGNITION";
    }
    
    cv::Size textName = ft2->getTextSize(type, fontHeight, thinkness, &baseline);
    ft2->putText(frame, type, cv::Point((frame.cols - textName.width) /2 - 160,  10 + textName.height), fontHeight ,cv::Scalar(255, 255, 255), thinkness, linestype, true);
    ft2->putText(frame, type, cv::Point((frame.cols - textName.width) /2 + 1 - 160, 11 + textName.height), fontHeight ,cv::Scalar(255, 255, 255), thinkness, linestype, true);
    // cv::imwrite("test1.jpg",frame);
    int px = 10;
    int py = 1080 - 10 -100 -90;
    // int py = 500;
    showLogo(frame, px, py);
    this->displayBoard->put(frame, this->index);
}