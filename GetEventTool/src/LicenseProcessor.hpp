#ifndef LicenseProcessor_hpp
#define LicenseProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
// #include "LicenseEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"


class LicenseProcessor : public GetImageEngine{
public: 
    LicenseProcessor();
    ~LicenseProcessor();
    void handleRequest(std::string& message);
    std::string nameImage();

    std::vector<std::string> licenses;
};
#endif 