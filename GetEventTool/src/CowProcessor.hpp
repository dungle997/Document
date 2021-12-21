#ifndef CowProcessor_hpp
#define CowProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "CowEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"

class CowProcessor : public GetImageEngine{
public: 
    CowProcessor();
    ~CowProcessor();
    void process(const std::string& ipcamera, const std::string& username, const std::string& userpwd);
};
#endif 