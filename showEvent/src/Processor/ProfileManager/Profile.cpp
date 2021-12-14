//
//  Profile.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "Profile.hpp"

Profile::Profile(std::string id, const std::string name, const std::string position, const cv::Mat portrait) {
    this->id = id;
    this->name = name;
    this->position = position;
    // cv::resize(portrait, this->portrait, cv::Size(180, 240));
    cv::resize(portrait, this->portrait, cv::Size(284, 346));
    int fontHeight = 20;
    int thickness = -1;
    int baseline = 0;
    int linestype = cv::LINE_AA;

    cv::Ptr<cv::freetype::FreeType2> ft2;
    ft2 = cv::freetype::createFreeType2();
    ft2->loadFontData(FONT_PATH, 0);
    cv::Size ts = ft2->getTextSize(name, fontHeight, thickness, &baseline);

    int tx = (this->portrait.cols - ts.width) / 2;
    int ty = 10 + ts.height;
    
    ft2->putText(this->portrait, name, cv::Point(tx + 1, ty + 1),fontHeight, cv::Scalar(0, 117, 0), thickness, linestype, true);
    ft2->putText(this->portrait, name, cv::Point(tx, ty), fontHeight, cv::Scalar(0, 210, 0), thickness, linestype, true);
    cv::resize(this->portrait, this->mini, cv::Size(195, 238));
}

Profile::~Profile() {
    
}

