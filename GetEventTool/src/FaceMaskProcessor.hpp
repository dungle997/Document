#ifndef FaceMaskProcessor_hpp
#define FaceMaskProcessor_hpp

#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "FaceMaskEvent.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "GetImageEngine.hpp"
class FaceMaskProcessor : public GetImageEngine{
public: 
    FaceMaskProcessor();
    ~FaceMaskProcessor();
    void process(const std::string& ipcamera, const std::string& username, const std::string& userpwd);
};
#endif 