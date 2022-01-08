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
                // obj->dirLastEventID = DEFINE(ipcamera,"personcount");
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
            if (monitor["type"] == "facemask") {
                std::string ipcamera = monitor["ipcamera"];
                std::string username = monitor["username"];
                std::string userpwd = monitor["userpwd"];
                obj = new FaceMaskProcessor();
                obj->ipcamera = ipcamera;
                obj->username = username;
                obj->userpwd = userpwd;
                obj->access_token = obj->get_Token(ipcamera, username, userpwd); 
                obj->dirLastEventID = "../Data_EventId/" + ipcamera + "/facemask.txt";
                // obj->dirLastEventID = DEFINE(ipcamera,"personcount");
                obj->dirSaveJson = "../Json_Event/" + ipcamera + "/facemask.txt";
                obj->lastID = obj->loadLastID(obj->dirLastEventID); 
                obj->urlJson = "https://" + ipcamera + ":4004/api/event/facemask?lastId="+ std::to_string(obj->lastID) + "&access_token=" + obj->access_token;
                obj->urlFrame = "https://"+ ipcamera + ":4004/api/event/frame/facemask/";
                obj->process();
            }
            if (monitor["type"] == "facerecognize") {
                std::string ipcamera = monitor["ipcamera"];
                std::string username = monitor["username"];
                std::string userpwd = monitor["userpwd"];
                obj = new FaceProcessor();
                obj->ipcamera = ipcamera;
                obj->username = username;
                obj->userpwd = userpwd;
                obj->access_token = obj->get_Token(ipcamera, username, userpwd); 
                obj->dirLastEventID = "../Data_EventId/" + ipcamera + "/face.txt";
                // obj->dirLastEventID = DEFINE(ipcamera,"personcount");
                obj->dirSaveJson = "../Json_Event/" + ipcamera + "/face.txt";
                obj->lastID = obj->loadLastID(obj->dirLastEventID); 
                obj->urlJson = "https://" + ipcamera + ":4004/api/event/facerecognition?lastId="+ std::to_string(obj->lastID) + "&access_token=" + obj->access_token;
                obj->urlFrame = "https://"+ ipcamera + ":4004/api/event/frame/facerecognition/";
                obj->process();
            }
            if (monitor["type"] == "firedetect") {
                std::string ipcamera = monitor["ipcamera"];
                std::string username = monitor["username"];
                std::string userpwd = monitor["userpwd"];
                obj = new FireProcessor();
                obj->ipcamera = ipcamera;
                obj->username = username;
                obj->userpwd = userpwd;
                obj->access_token = obj->get_Token(ipcamera, username, userpwd); 
                obj->dirLastEventID = "../Data_EventId/" + ipcamera + "/firedetect.txt";
                // obj->dirLastEventID = DEFINE(ipcamera,"personcount");
                obj->dirSaveJson = "../Json_Event/" + ipcamera + "/firedetect.txt";
                obj->lastID = obj->loadLastID(obj->dirLastEventID); 
                obj->urlJson = "https://" + ipcamera + ":4004/api/event/firedetect?lastId="+ std::to_string(obj->lastID) + "&access_token=" + obj->access_token;
                obj->urlFrame = "https://"+ ipcamera + ":4004/api/event/frame/firedetect/";
                obj->process();
            }
            // if (monitor["type"] == "objectdetect") {
            //     std::string ipcamera = monitor["ipcamera"];
            //     std::string username = monitor["username"];
            //     std::string userpwd = monitor["userpwd"];
            //     obj = new ObjectProcessor();
            //     obj->ipcamera = ipcamera;
            //     obj->username = username;
            //     obj->userpwd = userpwd;
            //     obj->access_token = obj->get_Token(ipcamera, username, userpwd); 
            //     obj->dirLastEventID = "../Data_EventId/" + ipcamera + "/personcount.txt";
            //     // obj->dirLastEventID = DEFINE(ipcamera,"personcount");
            //     obj->dirSaveJson = "../Json_Event/" + ipcamera + "/personcount.txt";
            //     obj->lastID = obj->loadLastID(obj->dirLastEventID); 
            //     obj->urlJson = "https://" + ipcamera + ":4004/api/event/persondetection?lastId="+ std::to_string(obj->lastID) + "&access_token=" + obj->access_token;
            //     obj->urlFrame = "https://"+ ipcamera + ":4004/api/event/frame/persondetection/";
            //     obj->process();
            // }
            if (monitor["type"] == "socialdistancing") {
                std::string ipcamera = monitor["ipcamera"];
                std::string username = monitor["username"];
                std::string userpwd = monitor["userpwd"];
                obj = new DistancingProcessor();
                obj->ipcamera = ipcamera;
                obj->username = username;
                obj->userpwd = userpwd;
                obj->access_token = obj->get_Token(ipcamera, username, userpwd); 
                obj->dirLastEventID = "../Data_EventId/" + ipcamera + "/distancing.txt";
                // obj->dirLastEventID = DEFINE(ipcamera,"personcount");
                obj->dirSaveJson = "../Json_Event/" + ipcamera + "/distancing.txt";
                obj->lastID = obj->loadLastID(obj->dirLastEventID); 
                obj->urlJson = "https://" + ipcamera + ":4004/api/event/socialdistancing?lastId="+ std::to_string(obj->lastID) + "&access_token=" + obj->access_token;
                obj->urlFrame = "https://"+ ipcamera + ":4004/api/event/frame/socialdistancing/";
                obj->process();
            }
            if (monitor["type"] == "license") {
                
                std::string ipcamera = monitor["ipcamera"];
                std::string username = monitor["username"];
                std::string userpwd = monitor["userpwd"];
                obj = new LicenseProcessor();
                obj->ipcamera = ipcamera;
                obj->username = username;
                obj->userpwd = userpwd;
                obj->access_token = obj->get_Token(ipcamera, username, userpwd); 
                obj->dirLastEventID = "../Data_EventId/" + ipcamera + "/license.txt";
                // obj->dirLastEventID = DEFINE(ipcamera,"personcount");
                obj->dirSaveJson = "../Json_Event/" + ipcamera + "/license.txt";
                obj->lastID = obj->loadLastID(obj->dirLastEventID); 
                obj->urlJson = "https://" + ipcamera + ":4004/api/event/vehicledetection?lastId="+ std::to_string(obj->lastID) + "&access_token=" + obj->access_token;
                obj->urlFrame = "https://"+ ipcamera + ":4004/api/event/frame/vehicledetection/";
                obj->process();
            }
        }
        delete obj;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}