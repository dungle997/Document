#ifndef FaceProcessor_hpp
#define FaceProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
// #include "FaceEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"

class FaceProcessor : public GetImageEngine{
public: 
    FaceProcessor();
    ~FaceProcessor();
    void handleRequest(std::string& message);
    std::string nameImage();

    std::vector<std::string> profileId;
};
#endif 