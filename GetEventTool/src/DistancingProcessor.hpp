#ifndef DistancingProcessor_hpp
#define DistancingProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"

class DistancingProcessor : public GetImageEngine{
public: 
    DistancingProcessor();
    ~DistancingProcessor();
    void handleRequest(std::string& message);
    std::string nameImage();
    void drawBoxDistancing(cv::Mat& image);
    std::vector<std::vector<float>> distances;
};
#endif 