/******************************************************************************** 
Copyright (C) 2008-2009, SmartHome Co., Ltd. All rights reserved.
Product: AICAM
Module: 
Version: 1.0
Author: 
Created: 
Modified: 
    <Name>
    <Date>
    <Change>
Released: 
Description: 
Note: <Note>
********************************************************************************/
/*-----------------------------------------------------------------------------*/
/* Header inclusions                                                           */
/*-----------------------------------------------------------------------------*/
#ifndef HttpServer_hpp
#define HttpServer_hpp

#include <iostream>
#include <fstream>
#include <ctime>
#include <regex>
#include <string>
#include <cstring>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/http.h>
#include <event2/http_struct.h>
#include <event2/http_compat.h>
#include <opencv2/opencv.hpp>
#include <event2/event_struct.h>
#include <event2/event.h>
#include <event2/event_compat.h>
#include <event2/buffer.h>
#include <event2/buffer_compat.h>
#include <event2/bufferevent_struct.h>
#include <event2/bufferevent_compat.h>
#include <event2/tag.h>
#include <event2/tag_compat.h>
#include "json.h"
#include "MonitorManager.hpp"
// #include "../AiConfig/Config.hpp"

#define PORT_SERVER 2001

class HttpServer 
{
    public:
        HttpServer(MonitorManager* monitorManager);
        virtual ~HttpServer();
        virtual void loop();
    private:
        // std::string buff_bad_request;
        // cv::Mat frame;
        MonitorManager* monitorManager = nullptr;
        // json process_restore;
        // bool first_reboot;
        static void callback(struct evhttp_request* request, void* param);
        static const std::string readContent(struct evhttp_request* request);
        static const std::string readHeader(struct evhttp_request* request);
        // bool standard_check();
        // static const std::string readIpClient(struct evhttp_request* request);
    protected:
        struct event_base* base = NULL;
        struct evhttp* server = NULL;
        static void sendError(struct evhttp_request* request, int status, const std::string& message);
        static void sendJson(struct evhttp_request* request, int status, const json& j);
        static void sendText(struct evhttp_request* request, int status, const std::string& text);
};
#endif /* HttpServer_hpp */
