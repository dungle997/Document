#ifndef FireProcessor_hpp
#define FireProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "FireEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"

class FireProcessor : public GetImageEngine{
public: 
    FireProcessor();
    ~FireProcessor();
    void process(const std::string& ipcamera, const std::string& username, const std::string& userpwd);
};
#endif 