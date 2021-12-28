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
std::string RtspThread::getTime(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	char timer[70];
	sprintf(timer, "%02d/%02d/%02d   %02d:%02d:%02d", ltm->tm_mday,ltm->tm_mon + 1,ltm->tm_year + 1900 ,ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
	std::string time= std::string(timer);
	return time;
} 
void RtspThread::start() {
    pthread_create(&this->thread, NULL, threadFunc, this);
}
int RtspThread::countDisconnect = 0;
int RtspThread::countReconnect = 0;

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
                    this->disconnectFlag = true;
                    // this->licenseEvents.insert(this->licenseEvents.begin(), event);
                    this->statusConnect.insert(this->statusConnect.begin(), this->disconnectFlag);
                    std::cout << "hello .." << std::endl;
                    // cv::Mat disconnect;    //
                    // this->disconnectVideo >> disconnect; //
                    // this->processor->process(this->disconnectImage); //
                    // std::cout << "Number of Disconnect = " << countDisconnect << std::endl;
                    break;
                }
                else{
                    this->disconnectFlag = false;
                    this->statusConnect.insert(this->statusConnect.begin(), this->disconnectFlag);
                    this->processor->process(image);
                    //sleep(0.1);
                    if (this->statusConnect.size() > 1 ){
                        if (this->statusConnect[0] != this->statusConnect[1] && this->statusConnect[0] == true){
                            this->countDisconnect++;
                            this->statusDisconnect = true;
                        }
                        if (this->statusConnect[0] != this->statusConnect[1] && this->statusConnect[0] == false){
                            this->countReconnect++;
                            this->statusReconnect = true;
                        }
                    }
                    while (this->statusConnect.size() > 2){
                        this->statusConnect.pop_back();
                    }
                    if (this->statusDisconnect == true){
                        std::cout << "111111111111111111" << std::endl;
                        this->myfile.open("thongkeketnoi.csv", std::ios::out | std::ios::app);
                        // std::cout << "adfadsf = " << RtspThread::getTime() << std::endl;
                        this->myfile << "Disconnect"<< ";" << RtspThread::getTime() << ";" << this->countDisconnect << endl;
                        // this->myfile << "Reconnect"<< ";" << RtspThread::getTime() << ";" << this->countReconnect << endl;
                        this->myfile.close();
                    }
                    if (this->statusReconnect == true){
                        std::cout << "22222222222222222222" << std::endl;
                        this->myfile.open("thongkeketnoi.csv", std::ios::out | std::ios::app);
                        // std::cout << "adfadsf = " << RtspThread::getTime() << std::endl;
                        // this->myfile << "Disconnect"<< ";" << RtspThread::getTime() << ";" << this->countDisconnect << endl;
                        this->myfile << "Reconnect"<< ";" << RtspThread::getTime() << ";" << this->countReconnect << endl;
                        this->myfile.close();
                    }
                    this->statusDisconnect = false;
                    this->statusReconnect = false;
                } 
            }
            if (this->statusConnect.size() > 1 ){
                if (this->statusConnect[0] != this->statusConnect[1] && this->statusConnect[0] == true){
                    this->countDisconnect++;
                    this->statusDisconnect = true;
                }
                if (this->statusConnect[0] != this->statusConnect[1] && this->statusConnect[0] == false){
                    this->countReconnect++;
                    this->statusReconnect = true;
                }
            }
            while (this->statusConnect.size() > 2){
                this->statusConnect.pop_back();
            }
            if (this->statusDisconnect == true){
                std::cout << "111111111111111111a" << std::endl;
                this->myfile.open("thongkeketnoi.csv", std::ios::out | std::ios::app);
                // std::cout << "adfadsf = " << RtspThread::getTime() << std::endl;
                this->myfile << "Disconnect"<< ";" << RtspThread::getTime() << ";" << this->countDisconnect << endl;
                // this->myfile << "Reconnect"<< ";" << RtspThread::getTime() << ";" << this->countReconnect << endl;
                this->myfile.close();
            }
            if (this->statusReconnect == true){
                std::cout << "22222222222222222222a" << std::endl;
                this->myfile.open("thongkeketnoi.csv", std::ios::out | std::ios::app);
                // std::cout << "adfadsf = " << RtspThread::getTime() << std::endl;
                // this->myfile << "Disconnect"<< ";" << RtspThread::getTime() << ";" << this->countDisconnect << endl;
                this->myfile << "Reconnect"<< ";" << RtspThread::getTime() << ";" << this->countReconnect << endl;
                this->myfile.close();
            }
            this->statusDisconnect = false;
            this->statusReconnect = false;
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
