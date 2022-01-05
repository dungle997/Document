//
//  LoadProcessor.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 04/11/2020.
//  Copyright © 2019 Nguyen Xuan Truong. All rights reserved.
//

#include "Load.hpp"

#define DEFINE(x,y) std::string("../Data_EventId/" + x + std::string(y) + ".txt")

LoadProcessor::LoadProcessor() {
}

LoadProcessor::~LoadProcessor() {
}

void LoadProcessor::load() {
    try {
        GetImageEngine* obj = nullptr;
        for (auto monitor : config.monitors) {
            if (monitor["type"] == "personcount") {
                std::string ipcamera = monitor["ipcamera"];
                std::string username = monitor["username"];
                std::string userpwd = monitor["userpwd"];
                obj = new CountProcessor();
                obj->ipcamera = ipcamera;
                obj->username = username;
                obj->userpwd = userpwd;
                obj->access_token = obj->get_Token(ipcamera, username, userpwd); 
                obj->dirLastEventID = "../Data_EventId/" + ipcamera + "/personcount.txt";
                obj->dirLastEventID = DEFINE(ipcamera,"personcount");
                obj->dirSaveJson = "../Json_Event/" + ipcamera + "/personcount.txt";
                obj->lastID = obj->loadLastID(obj->dirLastEventID); 
                obj->urlJson = "https://" + ipcamera + ":4004/api/event/persondetection?lastId="+ std::to_string(obj->lastID) + "&access_token=" + obj->access_token;
                obj->urlFrame = "https://"+ ipcamera + ":4004/api/event/frame/persondetection/";
                obj->process();
            }
            
            // if (monitor["type"] == "facedetect") {
            //     obj = new FaceDetectProcessor();
            //     std::string ipcamera = monitor["ipcamera"];
            //     std::string username = monitor["username"];
            //     std::string userpwd = monitor["userpwd"];
            //     obj->process(ipcamera, username, userpwd);
            // }
            // if (monitor["type"] == "facemask") {
            //     obj = new FaceMaskProcessor();
            //     std::string ipcamera = monitor["ipcamera"];
            //     std::string username = monitor["username"];
            //     std::string userpwd = monitor["userpwd"];
            //     obj->process(ipcamera, username, userpwd);
            // }
            // if (monitor["type"] == "facerecognize") {
            //     obj = new FaceProcessor();
            //     std::string ipcamera = monitor["ipcamera"];
            //     std::string username = monitor["username"];
            //     std::string userpwd = monitor["userpwd"];
            //     obj->process(ipcamera, username, userpwd);
            // }
            // if (monitor["type"] == "firedetect") {
            //     obj = new FireProcessor();
            //     std::string ipcamera = monitor["ipcamera"];
            //     std::string username = monitor["username"];
            //     std::string userpwd = monitor["userpwd"];
            //     obj->process(ipcamera, username, userpwd);
            // }
            // if (monitor["type"] == "objectdetect") {
            //     obj = new ObjectProcessor();
            //     std::string ipcamera = monitor["ipcamera"];
            //     std::string username = monitor["username"];
            //     std::string userpwd = monitor["userpwd"];
            //     obj->process(ipcamera, username, userpwd);
            // }
            // if (monitor["type"] == "socialdistancing") {
            //     obj = new DistancingProcessor();
            //     std::string ipcamera = monitor["ipcamera"];
            //     std::string username = monitor["username"];
            //     std::string userpwd = monitor["userpwd"];
            //     obj->process(ipcamera, username, userpwd);
            // }
            // if (monitor["type"] == "license") {
            //     obj = new LicenseProcessor();
            //     std::string ipcamera = monitor["ipcamera"];
            //     std::string username = monitor["username"];
            //     std::string userpwd = monitor["userpwd"];
            //     obj->process(ipcamera, username, userpwd);
            // }
        }
        delete obj;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}