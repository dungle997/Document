#ifndef ObjectProcessor_hpp
#define ObjectProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "ObjectEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"

class ObjectProcessor : public GetImageEngine{
public: 
    ObjectProcessor();
    ~ObjectProcessor();
    void process(const std::string& ipcamera, const std::string& username, const std::string& userpwd);
};
#endif 