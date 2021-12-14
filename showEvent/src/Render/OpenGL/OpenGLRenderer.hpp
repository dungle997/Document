//
//  OpenGLRenderer.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 15/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef OpenGLRenderer_hpp
#define OpenGLRenderer_hpp

#define DISPLAY_PORT 7000

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#elif defined(__linux__)
#include "../MJPEG/MJPEGWriter.hpp"
#include <glad/glad.h>
#endif

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "../../Processor/LoadProcessor/GlobalConfig.hpp"
#include "../Renderer.hpp"
#include <fstream>
#include <dirent.h>

class OpenGLRenderer: public Renderer {
public:
    OpenGLRenderer();
    ~OpenGLRenderer();
    virtual void prepare(const cv::Mat& frame);
    virtual void render();
    virtual bool running();
    
private:
    MJPEGWriter* jpegServer;
    // cv::VideoWriter writer;
    std::ifstream i;
    GLFWwindow* window;
    GLint mvp_location;
    GLint color_location;
};

#endif /* OpenGLRenderer_hpp */
