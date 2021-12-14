//
//  RtspThread.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 14/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef RtspThread_hpp
#define RtspThread_hpp

#include <unistd.h>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "../Processor/Processor.hpp"

using namespace std;
using namespace cv;

class RtspThread {
public:
    RtspThread(const String& url, Processor* processor);
    ~RtspThread();
    void start();
    
private:
    String url;
    Processor* processor;
    pthread_t thread;
    cv::Mat disconnectImage;

    void localThreadFunc();
    static void* threadFunc(void* arg);
};

#endif /* RtspThread_hpp */
