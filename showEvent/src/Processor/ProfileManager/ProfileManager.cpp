//
//  ProfileManager.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include <fstream>
#include <string>

#include "../../Config/json.h"
#include "PathHelper.hpp"
#include "ProfileManager.hpp"

using namespace std;

ProfileManager::ProfileManager() {
}

ProfileManager::~ProfileManager() {
    
}

void ProfileManager::load() {
    std::string path = PathHelper::makePath("profiles/profiles.json");
    // std::string path = this->pathProfile + "profiles/profiles.json";
    ifstream is(path);
    if (is.is_open()) {
        std::string content((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
        
        try {
            auto ar = json::parse(content);
            for (auto i = 0; i < ar.size(); i++) {
                try {
                    auto j = ar[i];
                    std::string id;
                    std::string name;
                    std::string portrait;
                    std::string position;
                    REQUIRED(j, id);
                    REQUIRED(j, name);
                    REQUIRED(j, portrait);
                    REQUIRED(j, position);
                    
                    std::string fullpath = PathHelper::makePath("profiles/" + portrait);
                    printf("%s\n", fullpath.c_str());
                    cv::Mat image = cv::imread(fullpath);
                    Profile* profile = new Profile(id, name, position, image);
                    this->profiles[id] = profile;
                }
                catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        is.close();
    }
}
