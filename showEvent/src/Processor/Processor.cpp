//
//  Processor.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 14/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "Processor.hpp"

Processor::Processor() {
    
}

Processor::~Processor() {
    
}
void Processor::showLogo(cv::Mat& frame, int& px, int& py){
    cv::Mat icon = cv::imread(AIVIEW_ICON_PATH);
    if (!icon.empty()){
        int width = 400;
        int height = 100;
        cv::Rect roiIcon(0, 0, width, height);
        cv::Rect roiFrame(px, py, width, height);
        // px =10 
        // py = 1080 - 10 - height - 90

        cv::resize(icon, icon, cv::Size(width, height));

        cv::addWeighted(frame(roiFrame), 0.6, icon(roiIcon) , 0.4 , 0.0 ,frame(roiFrame));    
    }
    else {
        std::cout << "Not Found LoGo AIView Image" << std::endl;
    }
}