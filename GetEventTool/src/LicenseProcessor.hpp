#ifndef LicenseProcessor_hpp
#define LicenseProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "LicenseEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"


class LicenseProcessor : public GetImageEngine{
public: 
    LicenseProcessor();
    ~LicenseProcessor();
    void process(const std::string& ipcamera, const std::string& username, const std::string& userpwd);
};
#endif 