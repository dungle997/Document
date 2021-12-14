//
//  GlobalConfig.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 04/11/2020.
//  Copyright © 2019 Nguyen Xuan Truong. All rights reserved.
//

#ifndef GlobalConfig_hpp
#define GlobalConfig_hpp

#include "../../Config/config.h"
#include <fstream>
#include <string>
#include <iostream>
#include "../../Config/json.h"
// #include "Config/config.h"


class GlobalConfig {
public:
    GlobalConfig ();
    ~GlobalConfig ();

    std::string language;
    std::string profilePath;
    json monitors;
    bool fullscreen;
    int row;
    int cols;
    bool isFullHD;
    void load();
};
extern GlobalConfig config;
#endif /* GlobalConfig_hpp */

