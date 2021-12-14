//
//  OpenCVRenderer.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 14/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef OpenCVRenderer_hpp
#define OpenCVRenderer_hpp

#include "../Renderer.hpp"

class OpenCVRenderer: public Renderer {
public:
    OpenCVRenderer();
    ~OpenCVRenderer();
    
    virtual void prepare(const cv::Mat& frame);
    virtual void render();
    virtual bool running();
    
private:
    cv::Mat frame;
    bool exitPending;
};

#endif /* OpenCVRenderer_hpp */
