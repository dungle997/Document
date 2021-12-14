//
//  ObjectManager.cpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 03/09/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//

#include "ObjectManager.hpp"

ObjectManager::ObjectManager() {
}

ObjectManager::~ObjectManager() {
}

void ObjectManager::load() {
    std::string path = PathHelper::makePath("objectlist.txt");
    std::cout<< "Load Object data." << std::endl;
    std::fstream objectFile(path);
    try {
        if(objectFile.is_open()) {
            std::string object;
            while (getline(objectFile, object)) {
                this->objectName.push_back(object) ;
            }
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    objectFile.close();
}