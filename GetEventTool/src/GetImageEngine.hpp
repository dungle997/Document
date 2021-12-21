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
#include <ctime>
#include <vector>

class GetImageEngine{
public:
    GetImageEngine();
    virtual ~GetImageEngine();
    std::string access_token;
    static std::string get_Token(const std::string& ipcamera,const std::string& username,const std::string& userpwd);
    virtual void process(const std::string& ipcamera, const std::string& username,const std::string& userpwd) = 0;
};
