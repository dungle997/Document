//
//  Renderer.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 14/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    virtual void prepare(const cv::Mat& frame) = 0;
    virtual void render() = 0;
    virtual bool running() = 0;
};

#endif /* Renderer_hpp */
