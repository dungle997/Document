#ifndef FaceProcessor_hpp
#define FaceProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "FaceEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"

class FaceProcessor : public GetImageEngine{
public: 
    FaceProcessor();
    ~FaceProcessor();
    void process(const std::string& ipcamera, const std::string& username, const std::string& userpwd);
};
#endif 