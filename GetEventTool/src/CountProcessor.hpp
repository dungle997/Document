#ifndef CountProcessor_hpp
#define CountProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "CountEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"

class CountProcessor : public GetImageEngine{
public: 
    CountProcessor();
    ~CountProcessor();
    void process(const std::string& ipcamera, const std::string& username, const std::string& userpwd);
};
#endif 