#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include "json.h"
#include "HttpSession.hpp"
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <vector>

class GetImageEngine{
public:
    GetImageEngine();
    virtual ~GetImageEngine();
    std::fstream myfile;
    std::string access_token;
    std::string ipcamera;
    std::string username;
    std::string userpwd;
    std::string dirLastEventID;
    std::string urlJson;
    std::string urlFrame;
    std::string dirSaveJson;
    HttpSession* jsonSession = nullptr;
    HttpSession* imageSession = nullptr;
    cv::Mat imageEvent;
    int lastID = 1;
    int loadLastID (std::string& path);
    void saveJson(std::string& path, std::string& message, std::string& time);
    void overrideLastID (std::string& path, int& lastID);
    static std::string getTime(); 
    std::string get_Token(const std::string& ipcamera,const std::string& username,const std::string& userpwd);
    // virtual void process(const std::string& ipcamera, const std::string& username,const std::string& userpwd) = 0;
    void process();
    virtual void handleRequest(std::string& message) = 0;
    void getImage(std::string& currentFrameUrl);
    std::string getJson();
    int convertTimeStamp(std::string& time);
};
