#ifndef FaceDetectProcessor_hpp
#define FaceDetectProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "FaceDetectEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"

class FaceDetectProcessor : public GetImageEngine{
public: 
    FaceDetectProcessor();
    ~FaceDetectProcessor();
    void process(const std::string& ipcamera, const std::string& username, const std::string& userpwd);
};
#endif 