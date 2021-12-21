#ifndef GlobalConfig_hpp
#define GlobalConfig_hpp
#include "json.h"
#include <fstream>
#include <string>
#include <iostream>

class GlobalConfig {
public:
    GlobalConfig ();
    ~GlobalConfig ();

    // std::string ipcamera;
    // std::string type;
    json monitors;
    // bool fullscreen;
    // int row;
    // int cols;
    // bool isFullHD;
    void load();
};
extern GlobalConfig config;
#endif /* GlobalConfig_hpp */

