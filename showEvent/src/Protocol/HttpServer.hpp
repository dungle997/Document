//
//  HttpServer.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef HttpServer_hpp
#define HttpServer_hpp

#include <string>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <evhttp.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <thread>

#include "../Config/json.h"
#include "../EventManager/EventManager.hpp"
#include "../Processor/ObjectManager/ObjectManager.hpp"
#define HTTP_PORT 8015
// #include "WebsocketServer.hpp"

class HttpServer {
public:
    HttpServer(EventManager* eventManager, ObjectManager* objectManager);
    virtual ~HttpServer();
    virtual void loop();
    static const std::string readIpClient(struct evhttp_request* request);
    
private:
    int maxFace;
    int maxFaceMask;
    bool isFirstFace;
    bool isFirstFaceMask;
    EventManager* eventManager;
    ObjectManager* objectManager;
    struct event_base* base;
    struct evhttp* server;
    static void callback(struct evhttp_request* request, void* param);
    
    static const std::string readContent(struct evhttp_request* request);
    // static const cv::Mat readImage(struct evhttp_request* request);
    static void readImage(struct evhttp_request* request, cv::Mat& image);
    
    static void sendError(struct evhttp_request* request, int status, const std::string& message);
    static void sendJson(struct evhttp_request* request, int status, const json& j);
    static void sendText(struct evhttp_request* request, int status, const std::string& text);
    
};


#endif /* HttpServer_hpp */
