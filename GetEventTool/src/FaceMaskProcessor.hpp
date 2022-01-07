#ifndef FaceMaskProcessor_hpp
#define FaceMaskProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
// #include "FaceMaskEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"
class FaceMaskProcessor : public GetImageEngine{
public: 
    FaceMaskProcessor();
    ~FaceMaskProcessor();
    void handleRequest(std::string& message);
    std::string nameImage();

    std::vector<int> fmask;
};
#endif 