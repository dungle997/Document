//
//  OpenGLRenderer.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 15/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//


#include "../../Config/linmath.h"
#include "OpenGLRenderer.hpp"

static const char* vertex_shader_text =
"#version 110\n"
"uniform mat4 MVP;\n"
"attribute vec2 vPos;\n"
"varying vec2 texcoord;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    texcoord = vPos;\n"
"}\n";

static const char* fragment_shader_text =
"#version 110\n"
"uniform sampler2D texture;\n"
"uniform vec3 color;\n"
"varying vec2 texcoord;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color * texture2D(texture, texcoord).rgb, 1.0);\n"
"}\n";

static const vec2 vertices[4] = {
    { 0.f, 0.f },
    { 1.f, 0.f },
    { 1.f, 1.f },
    { 0.f, 1.f }
};

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

void selectView(int view);

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    static int currentView;
    if (action == GLFW_PRESS) {
        if(key == GLFW_KEY_ESCAPE){
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    //     else if (key == GLFW_KEY_1)
    //     {
    //         selectView(1);
    //         currentView = 1;
    //     }
    //     else if (key == GLFW_KEY_2)
    //     {
    //         selectView(2);
    //         currentView = 2; 
    //     }
    //     else if (key == GLFW_KEY_3)
    //     {
    //         selectView(3);
    //         currentView = 3;
    //     }
    //     else if (key == GLFW_KEY_4)
    //     {
    //         selectView(4);
    //         currentView = 4;
    //     }
    //     else if (key == GLFW_KEY_5)
    //     {
    //         selectView(5);
    //         currentView = 5;
    //     }
    //     // else if (key == GLFW_KEY_Y)
    //     // {
    //     //     selectView(6);
    //     //     currentView = 6;
    //     // }
    //     // else if (key == GLFW_KEY_U)
    //     // {
    //     //     selectView(7);
    //     //     currentView = 7;
    //     // }
    //     else if (key == GLFW_KEY_RIGHT || key == GLFW_MOUSE_BUTTON_1) {
    //         if(currentView >= 5)
    //         {
    //             currentView = 0;
    //         }
    //         currentView ++;
    //         selectView(currentView);
            
    //     }
    //     else if (key == GLFW_KEY_LEFT || key == GLFW_MOUSE_BUTTON_2) {

    //         if(currentView <= 1)
    //         {
    //             currentView = 6;
    //         }
    //         currentView --;

    //         selectView(currentView);
    //     }
    }
}

OpenGLRenderer::OpenGLRenderer() {
    GLFWmonitor* monitor = NULL;
    //  this->jpegServer = new MJPEGWriter(DISPLAY_PORT);//
    //  this->jpegServer->start();//
    // this->i.open("video.json");
    // if (this->writer.isOpened()) {
    //     this->writer.release();
    // }
    
    GLFWwindow* window;
    GLuint texture, program, vertex_buffer;
    GLint mvp_location, vpos_location, color_location, texture_location;
    GLuint vertex_shader, fragment_shader;
    int width, height;
    bool fullscreen = config.fullscreen;
    
    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
    if (fullscreen) {
        monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

        width  = mode->width;
        height = mode->height;
        
        printf("Fullscreen Mode: %d x %d\n", width, height);
    }
    else {
        width = 1280;
        height = 720;
    }

    window = glfwCreateWindow(width, height, "Display Board1", monitor, NULL);
    if (window == nullptr) {
        printf("Failed to create GLFW window.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    if (monitor != nullptr) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
#ifdef __linux__
    gladLoadGL();
#endif
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    mvp_location = glGetUniformLocation(program, "MVP");
    color_location = glGetUniformLocation(program, "color");
    texture_location = glGetUniformLocation(program, "texture");
    vpos_location = glGetAttribLocation(program, "vPos");

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glUseProgram(program);
    glUniform1i(texture_location, 0);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) 0);
    
    this->window = window;
    this->mvp_location = mvp_location;
    this->color_location = color_location;
}

OpenGLRenderer::~OpenGLRenderer() {
    //  this->jpegServer->stop();//
    glfwTerminate();
}

int numberFile() {
    int count = 0;
    if (auto dir = opendir("data/")) {
        while (auto f = readdir(dir)) {
            if (!f->d_name || f->d_name[0] == '.')
                continue; // Skip everything that starts with a dot

            count ++;
        }
        closedir(dir);
    }
    return count;
}

void OpenGLRenderer::prepare(const cv::Mat& frame) {
    if (frame.data != nullptr) {
        int width = frame.cols;
        int height = frame.rows;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, frame.data);
        // if (!this->writer.isOpened()) {
        //     std::string nameVideo = "data/" + std::to_string(numberFile()) + ".avi";
        //     this->writer.open(nameVideo, cv::CAP_FFMPEG, cv::VideoWriter::fourcc('a', 'v', 'c', '1'), 30, cv::Size(frame.cols, frame.rows));;
        // }
        // if (this->writer.isOpened()) {
        //     this->writer << frame;
        // }
        
        //  this->jpegServer->write(frame);//
        
    }
}

void OpenGLRenderer::render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    const vec3 color = { 1.0f, 1.0f, 1.0f };
    
    int width, height;
    mat4x4 mvp;
    glfwGetFramebufferSize(this->window, &width, &height);
    glViewport(0, 0, width, height);
    mat4x4_ortho(mvp, 0.f, 1.f, 1.f, 0.f, 0.f, 1.f);
    glUniformMatrix4fv(this->mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);
    glUniform3fv(this->color_location, 1, color);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

bool OpenGLRenderer::running() {
    return !glfwWindowShouldClose(this->window);
}
 
