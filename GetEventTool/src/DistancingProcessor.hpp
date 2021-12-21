#ifndef DistancingProcessor_hpp
#define DistancingProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "DistancingEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"

class DistancingProcessor : public GetImageEngine{
public: 
    DistancingProcessor();
    ~DistancingProcessor();
    void process(const std::string& ipcamera, const std::string& username, const std::string& userpwd);
};
#endif 