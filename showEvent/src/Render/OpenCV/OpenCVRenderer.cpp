//
//  OpenCVRenderer.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 14/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "OpenCVRenderer.hpp"

#define DISPLAY_BOARD_NAME "Display Board"

OpenCVRenderer::OpenCVRenderer() {
    namedWindow(DISPLAY_BOARD_NAME, cv::WINDOW_OPENGL);
    this->exitPending = false;
}

OpenCVRenderer::~OpenCVRenderer() {
    
}

void OpenCVRenderer::prepare(const cv::Mat& frame) {
    frame.copyTo(this->frame);
}

void OpenCVRenderer::render() {
  imshow(DISPLAY_BOARD_NAME, this->frame);
    this->exitPending = cv::waitKey(30) == 27; //esc button, press "esc" = 27, => exitPending = true => break
}

bool OpenCVRenderer::running() {
    return !this->exitPending;
} 
