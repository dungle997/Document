//
//  RtspThread.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 14/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "RtspThread.hpp"

RtspThread::RtspThread(const String& url, Processor* processor) {
    this->url = url;
    this->processor = processor;
    // this->disconnectImage = cv::imread("offline.jpg"); //
}

RtspThread::~RtspThread() {
    
}

void RtspThread::start() {
    pthread_create(&this->thread, NULL, threadFunc, this);
}

void RtspThread::localThreadFunc() {
    if (this->url.find("rtsp") == std::string::npos) {
        if (this->url.find("rtsp") == std::string::npos) {
            cv::Mat image = cv::imread(this->url);
            this->processor->process(image);
        }
    }
    else {
        while (true) {
            printf("Start retrieve from %s\n", url.c_str());
            Mat image;
            // setenv("OPENCV_FFMPEG_CAPTURE_OPTIONS", "rtsp_transport;udp", 1);
		    setenv("OPENCV_FFMPEG_CAPTURE_OPTIONS", "rtsp_transport;tcp", 1);
		    // setenv("OPENCV_FFMPEG_CAPTURE_OPTIONS", "protocol_whitelist udp", 1);
            VideoCapture cap(this->url, cv::CAP_FFMPEG);
            cap.set(CAP_PROP_BUFFERSIZE, 10000);
            // cap.set(CAP_PROP_FRAME_WIDTH, 1920);
            // cap.set(CAP_PROP_FRAME_HEIGHT, 1080);
            
            // cap.set(CAP_PROP_POS_FRAMES, 20);
            //
//          if (!this->disconnectVideo.isOpened()) {
//            this->disconnectVideo.open("../offline.mp4", cv::CAP_FFMPEG);
//          }
        
	        // VideoCapture cap(this->url, cv::CAP_GSTREAMER);
            // cap.set(CAP_PROP_BUFFERSIZE, 1);
            while (true) {
                
                //cap.set(CAP_PROP_POS_FRAMES, 0);
	            // for(int i = 0; i < 1000; i++) {
                // cap.grab();
                // cap.retrieve(image);
                cap >> image;
                if (image.empty()) {
                    std::cout << "hello .." << std::endl;
                    // cv::Mat disconnect;    //
                    // this->disconnectVideo >> disconnect; //
                    // this->processor->process(this->disconnectImage); //
                    break;
                }
                //else
                this->processor->process(image);
                //sleep(0.1); 
            }
            printf("RTSP stream ended.\n");
            sleep(1);
            //TungDM add
            // unsetenv("OPENCV_FFMPEG_CAPTURE_OPTIONS");
        }
    }
}

void* RtspThread::threadFunc(void* arg) {
    RtspThread* thread = (RtspThread*)arg;
    thread->localThreadFunc();
    pthread_exit(NULL);
}
