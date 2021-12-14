//
//  GlobalConfig.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 04/11/2020.
//  Copyright © 2019 Nguyen Xuan Truong. All rights reserved.
//
#include "GlobalConfig.hpp"

GlobalConfig config;

GlobalConfig::GlobalConfig() {
}
 

GlobalConfig::~GlobalConfig() {
}

void GlobalConfig::load() {
    std::ifstream is(CONFIG_JSON_PATH);
    if (is.is_open()) {
        std::string content((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
        try {
            auto j = json::parse(content);
            this->fullscreen = j["fullscreen"];
            this->isFullHD = j["FullHD"];
            this->language = j["language"];
            this->profilePath = j["profilePath"];
            this->row = j["row"];
            this->cols = j["cols"];
            this->monitors = j["monitors"];
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        
    }
}