//
//  LoadProcessor.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 04/11/2020.
//  Copyright © 2019 Nguyen Xuan Truong. All rights reserved.
//

#include "Load.hpp"

// #define DEFINE(x,y) std::string("../Data_EventId/" + x + std::string(y) + ".txt")

LoadProcessor::LoadProcessor() {
}

LoadProcessor::~LoadProcessor() {
}
void LoadProcessor::setParam(std::string& type, GetImageEngine* obj, std::string& ipcamera, std::string& username, std::string& userpwd, std::string& port){
    obj->ipcamera = ipcamera;
    obj->username = username;
    obj->userpwd = userpwd;
    obj->port = port;
    obj->access_token = obj->get_Token(obj->ipcamera, obj->username, obj->userpwd); 
    obj->dirLastEventID = "../Data_EventId/" + obj->ipcamera + "/" + type + ".txt";
    // obj->dirLastEventID = DEFINE(ipcamera,"personcount");
    obj->dirSaveJson = "../Json_Event/" + obj->ipcamera + "/" + type + ".txt";
    obj->lastID = obj->loadLastID(obj->dirLastEventID); 
    obj->urlJson = "https://" + obj->ipcamera + ":" + obj->port + "/api/event/" + type +"?lastId="+ std::to_string(obj->lastID) + "&access_token=" + obj->access_token;
    // std::cout << "urlJson = "<< obj->urlJson << std::endl;
    obj->urlFrame = "https://"+ obj->ipcamera + ":" + obj->port + "/api/event/frame/" + type + "/";
    obj->process();
}
void LoadProcessor::load() {
    try {
        GetImageEngine* obj = nullptr;
        for (auto monitor : config.monitors) {
            std::string port     = monitor["port"];
            std::string type     = monitor["type"];
            std::string ipcamera = monitor["ipcamera"];
            std::string username = monitor["username"];
            std::string userpwd  = monitor["userpwd"];
            obj = LoadSubClass(type, obj);
            setParam(type, obj, ipcamera, username, userpwd, port);
        }      
        delete obj;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}
GetImageEngine* LoadProcessor::LoadSubClass(std::string& type, GetImageEngine* obj){
    if (type == "persondetection") {
        obj = new CountProcessor();
    }
    if (type == "facemask") {
        obj = new FaceMaskProcessor();
    }
    if (type == "facerecognition") {
        obj = new FaceProcessor();
    }
    if (type == "firedetect") {
        obj = new FireProcessor();
    }
    if (type == "socialdistancing") {
        obj = new DistancingProcessor();
    }
    if (type == "vehicledetection") {
        obj = new LicenseProcessor();
    }
    return obj;
}