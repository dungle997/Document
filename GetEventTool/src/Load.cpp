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
void LoadProcessor::setParam(std::string& type, GetImageEngine* obj, std::string& ipcamera, std::string& username, std::string& userpwd, std::string& port, std::string& lastID){
    obj->type = type;
    obj->ipcamera = ipcamera;
    obj->username = username;
    obj->userpwd = userpwd;
    obj->port = port;
    obj->lastID = lastID;
    std::cout << "lastID = " << obj->lastID << std::endl;
    obj->access_token = obj->get_Token(obj->ipcamera, obj->username, obj->userpwd); 
    // obj->dirLastEventID = "../Data_EventId/" + obj->ipcamera + "/" + obj->type + ".txt";
    obj->dirSaveJson = "../Json_Event/" + obj->ipcamera + "/" + obj->type + ".txt";
    // obj->lastID = obj->loadLastID(obj->dirLastEventID); 
    obj->urlJson = "https://" + obj->ipcamera + ":" + obj->port + "/api/event/" + obj->type +"?lastId="+ obj->lastID + "&access_token=" + obj->access_token;
    // std::cout << "urlJson = "<< obj->urlJson << std::endl;
    obj->urlFrame = "https://"+ obj->ipcamera + ":" + obj->port + "/api/event/frame/" + obj->type + "/";
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
            std::string lastID   = monitor["lastID"];
            obj = LoadSubClass(type, obj);
            setParam(type, obj, ipcamera, username, userpwd, port, lastID);
            CheckPathExist(type, obj);
            obj->process();
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
bool LoadProcessor::IsPathExist(const std::string &s){
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}
void LoadProcessor::CheckPathExist(std::string& type, GetImageEngine* obj){
    std::string pathIpcamera = "../Event/" + obj->ipcamera;
    std::string pathType = "../Event/" + obj->ipcamera + "/" + type; 
    std::string com = "mkdir " + pathIpcamera;
    std::string com1 = "mkdir " + pathType; 
    std::string pathSaveJson = "../Json_Event/" + obj->ipcamera;
    std::string com2 = "mkdir " + pathSaveJson;
    // std::string pathDataEventId = "../Data_EventId/" + obj->ipcamera;
    // std::string com3 = "mkdir " + pathDataEventId;
    std::cout << "com = " << com << std::endl;
    if (IsPathExist(pathIpcamera)){
        std::cout << "Folder IP camera Exist" << std::endl;
    }
    else {
        system(com.c_str());
    }
    if (IsPathExist(pathType)){
        std::cout << "Folder Type Exist" << std::endl;
    }
    else {
        system(com1.c_str());
    }
    if (IsPathExist(pathSaveJson)){
        std::cout << "Folder Save Json Exist" << std::endl;
    }
    else {
        system(com2.c_str());
    }
    // if (IsPathExist(pathDataEventId)){
    //     std::cout << "Folder Save EventID Exist" << std::endl;
    // }
    // else {
    //     system(com3.c_str());
    // }
}