//
//  ObjectManager.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 03/09/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#ifndef ObjectManager_hpp
#define ObjectManager_hpp

#include <vector>
#include <fstream>
#include <iostream>
#include "../ProfileManager/PathHelper.hpp"

class ObjectManager {

public:
    ObjectManager();
    ~ObjectManager();

    void load();

    std::vector<std::string> objectName;

};

#endif /*ObjectManager_hpp*/