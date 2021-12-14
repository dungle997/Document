//
//  HttpServer.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//


#include "HttpServer.hpp"


#define LIBEVENT_LOOP_INTERVAL  30

HttpServer::HttpServer(EventManager* eventManager, ObjectManager* objectManager) {
    this->eventManager = eventManager;
    this->objectManager = objectManager;
    this->base = NULL;
    this->server = NULL;
    this->isFirstFace = true;
    this->isFirstFaceMask = true;
}

HttpServer::~HttpServer() {
    if (this->server != NULL) {
        evhttp_free(this->server);
    }
    if (this->base != NULL) {
        event_base_free(this->base);
    }
}

void HttpServer::loop() {
    if (this->base == NULL) {
        this->base = event_base_new();
    }
    else if (this->server == NULL) {
        this->server = evhttp_new(this->base);
        evhttp_set_allowed_methods(this->server, EVHTTP_REQ_GET | EVHTTP_REQ_POST | EVHTTP_REQ_PUT | EVHTTP_REQ_DELETE | EVHTTP_REQ_OPTIONS);
        evhttp_set_gencb(this->server, callback, this);
        
        if (evhttp_bind_socket(this->server, "0.0.0.0", HTTP_PORT) != 0) {
            std::cerr << "Failed to bind to 0.0.0.0:" << HTTP_PORT << std::endl;
        }
        else {
            std::cout << "HTTP Server Listening on 0.0.0.0:" << HTTP_PORT << std::endl;
        }
    }
    else {
        event_base_loop(this->base, EVLOOP_NONBLOCK);
    }
	usleep(1);
}

bool equal(const char* src, const char* dst) {
    return strcmp(src, dst) == 0;
}

bool startWith(const char** src, const char* dst) {
    const char* str = *src;
    size_t len = strlen(dst);
    if (strncmp(str, dst, len) == 0) {
        *src = str + len;
        return true;
    }
    else {
        return false;
    }
}
bool testCode(int& a, int& b){
    if (a > b){
        std::cout << "a > b" << std::endl;
    }
    else{
        std::cout << "a <= b" << std::endl;
    }
}

bool nextInt(const char** src, int* out) {
    int number = 0;
    bool found = false;
    const char* str = *src;
    while (*str) {
        char c = *str;
        if ((c >= '0') && (c <= '9')) {
            found = true;
            number = number * 10 + c - '0';
        }
        else if (c == '/') {
            break;
        }
        else {
            return false;
        }
        str++;
    }
    
    if (found) {
        *src = str + 1;
        *out = number;
        return true;
    }
    else {
        return false;
    }
}
const std::string HttpServer::readIpClient(struct evhttp_request *request) 
{
    char *client_ip;
    u_short client_port;
    evhttp_connection_get_peer(evhttp_request_get_connection(request), &client_ip, &client_port);
    std::string ip(client_ip);
    return ip;
}

void HttpServer::callback(struct evhttp_request* request, void* param) {
    HttpServer* server = (HttpServer*)param;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    const char* urisz = evhttp_request_get_uri(request);
    struct evhttp_uri* uri = evhttp_uri_parse(urisz);
    if (uri != NULL) {
        const char* path = evhttp_uri_get_path(uri);
        std::cout << path << std::endl;
        std::cout << "IPClient = " << readIpClient(request) << std::endl;
        // std::cout << urisz << std::endl;
        if (startWith(&path, "/face/") || startWith(&path,"/facerecognize/")) {
            std::string test_json;
            int cameraId;
            if (nextInt(&path, &cameraId) && (path != NULL) ) { //
                test_json = path;
                if (test_json.length() < 20){
                    std::cout << "path = " << test_json << std::endl;
                    std::string content = readContent(request);
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;
                    
                    
                    try {
                        auto j = json::parse(content);
                        auto crop_frame = j["crop_id"];
                        auto full_frame = j["image_id"];
                        std::string frame;
                        if (crop_frame.empty()){
                                frame = full_frame;
                        }
                        else{
                            frame = crop_frame[0];
                        }
                        auto objects = j["extras"]["objects"];
                        for (auto object : objects){
                            auto profileIds = object["profileId"];
                            if (profileIds.size() > 0) {
                                auto jLocation = object["locations"];
                                std::vector<cv::Rect> locations;
                                cv::Rect box(jLocation[0], jLocation[1], jLocation[2], jLocation[3]);
                                // locations.push_back(box);
                                
                                
                                char timer[25];
                                sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                                std::string time= std::string(timer);
                                std::string day = std::to_string(ltm->tm_mday) + "-" + std::to_string(ltm->tm_mon);
                                

                                    if (profileIds != "0") {
                                        FaceEvent* event = new FaceEvent(cameraId, profileIds, box , time, day, frame);
                                        server->eventManager->insertFaceEvent(event);
                                    }
                                    else {
                                        UnknownFaceEvent* event = new UnknownFaceEvent(cameraId, box , time, frame);
                                        server->eventManager->insertUnknownFaceEvent(event);
                                    }  
                            }
                        }
                    }
                    catch (std::exception& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
                else { //
                // sendText(request, 200, "{}");
                // std::cout << " -----------Received Image -----------" << std::endl;
                        std::string frame;
                        frame = path;
                        std::cout << "frame = "<< frame << std::endl;
                        // std::cout << "cameraId " << cameraId << std::endl;
                        // std::cout << "frame =" << frame << std::endl;
                        // cv::Mat image =readImage(request);
                        cv::Mat image;
                        readImage(request, image);
                        // if (cameraId==1){
                        std::cout << image.size() << std::endl;
                        // }
                        if (!image.empty()){
                            std::cout << image.size() << std::endl;
                            server->eventManager->updateFrame(frame, image, cameraId);
                        }
                }
                
                
        
            }
           
        }
        else if (startWith(&path, "/facedetect/")) {
            std::string test_json ;
            int cameraId;
            if (nextInt(&path, &cameraId) && (path != NULL)) { //
                test_json = path;
                if (test_json.length() < 20){
                    std::cout << "path = " << test_json << std::endl;
                    std::string content = readContent(request);
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;
                    try {
                            auto j = json::parse(content);
                            auto crop_frame = j["crop_id"];
                            auto full_frame = j["image_id"];
                            std::string frame;
                            if (crop_frame.empty()){
                                    frame = full_frame;
                            }
                            else{
                            frame = crop_frame[0];
                            }
                            char timer[25];
                            sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                            std::string time= std::string(timer);
                            auto objects = j["extras"]["objects"];
                            std::vector<cv::Rect> locations;
                            for(auto object : objects){
                                auto jLocations = object["locations"];
                                cv::Rect box(jLocations[0], jLocations[1], jLocations[2], jLocations[3]);
                                locations.push_back(box);
                            }
                            FaceDetectEvent* event = new FaceDetectEvent(cameraId, locations, time, frame);
                            server->eventManager->insertFaceDetectEvent(event);
                    }
                    catch (std::exception& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
                else { //
                // sendText(request, 200, "{}");
                // std::cout << " -----------Received Image -----------" << std::endl;
                    std::string frame;
                    frame = path;
                    std::cout << "frame = " << frame << std::endl;
                    // std::cout << "cameraId " << cameraId << std::endl;
                    // std::cout << "frame =" << frame << std::endl;
                    // cv::Mat image =readImage(request);
                    cv::Mat image;
                    readImage(request, image);
                    // if (cameraId==1){
                    //     std::cout << image.size() << std::endl;
                    // }
                    if (!image.empty()){
                        server->eventManager->updateFrame(frame, image, cameraId);
                    }
    
                
                }
            }
          
        }

        else if (startWith(&path, "/destructivealarm/") || (startWith(&path, "/accessalarm/")) || (startWith(&path, "/oppositedirectionalarm/")) || (startWith(&path, "/illegalparkingalarm/"))) {
            int cameraId;
            std::string test_json;
            if (nextInt(&path, &cameraId) && (path != NULL) ) { 
                test_json = path;
                if (test_json.length() < 20){
                    std::cout << "path = " << test_json << std::endl;
                    std::string content = readContent(request);
                    // std::cout << "ban tin json" << std::endl; 
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;
                    try {
                            auto j = json::parse(content);
                            // int frame;
                            auto crop_frame = j["crop_id"];
                            auto full_frame = j["image_id"];
                            std::string frame;
                            if (crop_frame.empty()){
                                    frame = full_frame;
                            }
                            else{
                                frame = crop_frame[0];
                            }
                            std::vector<cv::Rect> locations;
                            char timer[25];
                            sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                            std::string time= std::string(timer);
                            auto objects = j["extras"]["objects"];
                            for (auto object : objects){
                                auto jLocation = object["locations"];
                                cv::Rect box(jLocation[0], jLocation[1], jLocation[2], jLocation[3]);
                                locations.push_back(box);
                            }
                            AlarmEvent* event = new AlarmEvent(cameraId, locations, time, frame);
                            server->eventManager->insertAlarmEvent(event);   
                    }
                    catch (std::exception& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
                else { 
                    std::string frame;
                    frame = path;
                    std::cout << "frame = "<< frame << std::endl;
                    // std::cout << "cameraId " << cameraId << std::endl;
                    // std::cout << "frame =" << frame << std::endl;
                    // cv::Mat image =readImage(request);
                    cv::Mat image;
                    readImage(request, image);
                    // if (cameraId==1){
                    //     std::cout << image.size() << std::endl;
                    // }
                    if (!image.empty()){
                        server->eventManager->updateFrame(frame, image, cameraId);
                    }
                }
            }
           
        }
        else if (startWith(&path, "/count/") || startWith(&path,"/personcount/")) {
            int cameraId;
            std::string test_json;
            if (nextInt(&path, &cameraId) && (path != NULL)) {
                test_json = path;
                // std::cout << "path = " << path << std::endl;
                if (test_json.length() < 20 ){
                // if (nextInt(&path, &cameraId)) {
                    std::cout << "path = " << test_json << std::endl;
                    std::string content = readContent(request);
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;
                    try {
                        auto j = json::parse(content);
                        auto crop_frame = j["crop_id"];
                        auto full_frame = j["image_id"];
                        std::string frame;
                        if (crop_frame.empty()){
                                frame = full_frame;
                        }
                        else{
                            frame = crop_frame[0];
                        }
                        std::vector<cv::Rect> locations;
                        char timer[25];
                        sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                        std::string time= std::string(timer);
                        auto objects = j["extras"]["objects"];
                        for (auto object : objects){
                            auto jLocation = object["locations"];
                            cv::Rect box(jLocation[0], jLocation[1], jLocation[2], jLocation[3]);
                            locations.push_back(box);
                        }
                        CountEvent* event = new CountEvent(cameraId, locations, time, frame);
                        server->eventManager->insertCountEvent(event);
                    }
                    catch (std::exception& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
                else { //
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received Image -----------" << std::endl;
                    std::string frame;
                    frame = path;
                    std::cout << "frame = " << frame << std::endl;
                    // std::cout << "cameraId " << cameraId << std::endl;
                    // std::cout << "frame =" << frame << std::endl;
                    // cv::Mat image =readImage(request);
                    cv::Mat image;
                        readImage(request, image);
                    // if (cameraId==1){
                    //     std::cout << image.size() << std::endl;
                    // }
                    if (!image.empty()){
                        server->eventManager->updateFrame(frame, image, cameraId);
                    }
                }
            }
        }
        else if (startWith(&path, "/cowdetect/")) {
            int cameraId;
            std::string test_json;
            if (nextInt(&path, &cameraId) && (path != NULL) ) { //
                test_json = path;
                if (test_json.length() < 20){
                    std::cout << "path = " << test_json << std::endl;
                    std::string content = readContent(request);
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;
                    try {
                        auto j = json::parse(content);
                        auto crop_frame = j["crop_id"];
                        auto full_frame = j["image_id"];
                        std::string frame;
                        if (crop_frame.empty()){
                                frame = full_frame;
                        }
                        else{
                            frame = crop_frame[0];
                        }
                        std::vector<cv::Rect> locations;
                        char timer[25];
                        sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                        std::string time= std::string(timer);
                        auto objects = j["extras"]["objects"];
                        for (auto object : objects){
                            auto jLocation = object["locations"];
                            cv::Rect box(jLocation[0], jLocation[1], jLocation[2], jLocation[3]);
                            locations.push_back(box);
                        }
                        CowEvent* event = new CowEvent(cameraId, locations, time, frame);
                        server->eventManager->insertCowEvent(event);
                        
                    }
                    catch (std::exception& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
                else { //
                // sendText(request, 200, "{}");
                // std::cout << " -----------Received Image -----------" << std::endl;
                    std::string frame;
                    frame = path;
                    std::cout << "frame = " << frame << std::endl;
                        // std::cout << "cameraId " << cameraId << std::endl;
                        // std::cout << "frame =" << frame << std::endl;
                    // cv::Mat image =readImage(request);
                    cv::Mat image;
                        readImage(request, image);
                    // if (cameraId==1){
                    //     std::cout << image.size() << std::endl;
                    // }
                    if (!image.empty()){
                        server->eventManager->updateFrame(frame, image, cameraId);
                    }
                }
            }
        }
        else if (startWith(&path, "/license/")) {
            int cameraId;
            std::string test_json;
            if (nextInt(&path, &cameraId) && (path != NULL)) { 
                test_json = path;
                if (test_json.length() < 20){
                    std::cout << "path = " << test_json << std::endl;
                    std::string content = readContent(request);
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;
                    try {
                        auto j = json::parse(content);
                        // char timer[25];
                        // sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                        // std::string time= std::string(timer);
                        auto times = j["time"];
                        std::string time = times;
                        std::string time1 = time.erase(0, time.find('T') + 1);
                        time = time1.substr(0, 8);
                        std::cout << "time = "<< time << std::endl;
                        auto crop_frame = j["crop_id"];
                        auto full_frame = j["image_id"];
                        std::string frame;
                        if (crop_frame.empty()){
                                frame = full_frame;
                        }
                        else{
                            frame = crop_frame[0];
                        }
                        auto objects = j["extras"]["objects"];
                        for (auto object : objects){
                            auto confidence = object["confidence"];
                            auto jLicenses = object["license"];
                            auto locations = object["locations"];
                                if (jLicenses != "" && confidence > 0.8) {
                                    LicenseEvent* event = new LicenseEvent(cameraId, jLicenses, cv::Rect(cv::Point(locations[0], locations[1]), cv::Size(locations[2], locations[3])), time, frame, jLicenses);
                                    server->eventManager->insertLicenseEvent(event);
                                }
                    
                        }
                        
                    }
                    catch (std::exception& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
                else { 
                
                    std::string frame;
                    frame = path;
                    std::cout << "frame = " << frame << std::endl;
                        // std::cout << "cameraId " << cameraId << std::endl;
                        // std::cout << "frame =" << frame << std::endl;
                    // cv::Mat image =readImage(request);
                    cv::Mat image;
                        readImage(request, image);
                        // if (cameraId==1){
                            std::cout << image.size() << std::endl;
                        // }
                    if (!image.empty()){
                        std::cout << "akjdfkljdasfldjasfkljadsklf" << std::endl;
                        server->eventManager->updateFrame(frame, image, cameraId);
                    }
                }
            }
           
        }

        //add new traffic by TruongNXd 
        // else if (startWith(&path, "/traffic/")) {
        //     int cameraId;
        //     if (nextInt(&path, &cameraId)) {
        //         std::string content = readContent(request);
        //         std::cout << content << std::endl;
        //         sendText(request, 200, "{}");
        //         std::cout << " -----------Received data -----------" << std::endl;
        //         try {
        //             auto j = json::parse(content);
        //             std::string time;
        //             std::string frame;
        //             frame = j["image_id"];
        //             int countTraffic;
        //             REQUIRED(j, countTraffic);
        //             REQUIRED(j, time);
        //             REQUIRED(j, frame);
        //             auto ar = j["boxes"];
        //             std::vector<cv::Rect> boxes;
        //             for (int i = 0; i < ar.size(); i++) {
        //                 auto jj = ar[i];
        //                 int x;
        //                 int y;
        //                 int w;
        //                 int h;
        //                 REQUIRED(jj, x);
        //                 REQUIRED(jj, y);
        //                 REQUIRED(jj, w);
        //                 REQUIRED(jj, h);
        //                 boxes.push_back(cv::Rect(cv::Point(x, y), cv::Size(w, h)));
        //             }
        //             TrafficEvent* event = new TrafficEvent(cameraId, countTraffic, time, frame, boxes);
        //             server->eventManager->insertTraffic(event);
        //         }
        //         catch (std::exception& e) {
        //             std::cout << e.what() << std::endl;
        //         }
        //     }
        // }

        else if (startWith(&path, "/distancing/") || startWith(&path,"/socialdistancing/")) {
            int cameraId;
            std::string test_json;
            if (nextInt(&path, &cameraId) && (path != NULL)) { //
            // if (nextInt(&path, &cameraId)) {
                test_json = path;
                if(test_json.length() < 20){
                    std::cout << "path = " << test_json << std::endl;
                    std::string content = readContent(request);
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;
                    try {
                        auto j = json::parse(content);
                        auto crop_frame = j["crop_id"];
                        auto full_frame = j["image_id"];
                        std::string frame;
                        if (crop_frame.empty()){
                                frame = full_frame;
                        }
                        else{
                            frame = crop_frame[0];
                        }
                        char timer[25];
                        sprintf(timer, "%02d-%02d-%04d", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year +  1900);
                        std::string date = std::string(timer);
                        sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                        std::string time= std::string(timer);
                        std::vector<std::vector<float>> distances;
                        auto jdistances = j["extras"]["distancing"];
                        for(auto jdistance : jdistances) {
                            std::vector<float> distance;
                            for (auto id : jdistance) {
                                distance.push_back(id);
                            }
                            distances.push_back(distance);
                        }
                        std::vector<cv::Rect> boxes;
                        auto objects = j["extras"]["objects"];
                        for (auto object : objects){
                            auto jlocation = object["locations"];
                            cv::Rect box(jlocation[0], jlocation[1], jlocation[2], jlocation[3]);
                            boxes.push_back(box); 
                        }
                        DistancingEvent* event = new DistancingEvent(cameraId, boxes, distances, time, date, frame);
                        server->eventManager->insertDistancing(event);
                    }
                    catch (std::exception& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
                else { 
                    std::string frame;
                    frame = path;
                    std::cout << "frame = " << frame << std::endl;
                    // cv::Mat image =readImage(request);
                    cv::Mat image;
                        readImage(request, image);
                    if (!image.empty()){
                        server->eventManager->updateFrame(frame, image, cameraId);
                    }
                
                }
                
            }
           
        }

        else if (startWith(&path, "/facemask/")) {
            int cameraId;
            std::string test_json;
            if (nextInt(&path, &cameraId) && (path != NULL)) { 
                test_json = path;
                if (test_json.length() < 20){
                    std::cout << "path = "<< test_json << std::endl;
                    std::string content = readContent(request);
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;
                    try {
                        auto j = json::parse(content);
                        auto crop_frame = j["crop_id"];
                        auto full_frame = j["image_id"];
                        std::string frame;
                        if (crop_frame.empty()){
                                frame = full_frame;
                        }
                        else{
                            frame = crop_frame[0];
                        }
                        char timer[25];
                        sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                        std::string time= std::string(timer);
                        auto objects = j["extras"]["objects"];
                        for (auto object : objects){
                            auto jLocation = object["locations"];
                                cv::Rect box(jLocation[0], jLocation[1], jLocation[2], jLocation[3]);
                                auto fmask = object["fmask"];
                               
                                    if(fmask == 1) {
                                        FaceMaskEvent* event = new FaceMaskEvent(cameraId, box, time, frame);
                                        server->eventManager->insertFaceMaskEvent(event);
                                    } 
                                    else{
                                        NoFaceMaskEvent* event = new NoFaceMaskEvent(cameraId, box, time, frame);
                                        server->eventManager->insertNoFaceMaskEvent(event);
                                    }   
                        }
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                } 
                else { //
                    std::string frame;
                    frame = path;
                    std::cout << "frame = " << frame << std::endl;
                    cv::Mat image;
                        readImage(request, image);
                    if (!image.empty()){
                        server->eventManager->updateFrame(frame, image, cameraId);
                    }
                }
                
            }
            
            
        }
        
        else if (startWith(&path, "/firedetect/")) {
            int cameraId;
            std::string test_json;
            if (nextInt(&path, &cameraId) && (path != NULL)) { 
                test_json = path;
                if (test_json.length() < 20){
                    std::cout << "path = " << test_json << std::endl;
                    std::string content = readContent(request);
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;

                    try {
                        auto j = json::parse(content);
                        auto crop_frame = j["crop_id"];
                        auto full_frame = j["image_id"];
                        std::string frame;
                        if (crop_frame.empty()){
                                frame = full_frame;
                        }
                        else{
                            frame = crop_frame[0];
                        }
                        std::vector<cv::Rect> locations;
                        char timer[25];
                        sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                        std::string time= std::string(timer);
                        auto objects = j["extras"]["objects"];
                        for (auto object : objects){
                            auto jLocation = object["locations"];
                            cv::Rect box(jLocation[0], jLocation[1], jLocation[2], jLocation[3]);
                            locations.push_back(box);
                        }
                        FireEvent* event = new FireEvent(cameraId, locations, time, frame);
                        server->eventManager->insertFireEvent(event);
                    
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }      
                }
                else {  
                    std::string frame;
                    frame = path;
                    std::cout << "frame = "<< frame << std::endl;
                            // std::cout << "cameraId " << cameraId << std::endl;
                            // std::cout << "frame =" << frame << std::endl;
                    // cv::Mat image =readImage(request);
                    cv::Mat image;
                        readImage(request, image);
                    // if (cameraId==1){
                    //     std::cout << image.size() << std::endl;
                    // }
                    if (!image.empty()){
                        server->eventManager->updateFrame(frame, image, cameraId);
                    }
                }
            }
            
        }

        else if (startWith(&path, "/object/") || startWith(&path, "/objectdetect/")) {
            int cameraId;
            std::string test_json;
            if (nextInt(&path, &cameraId) && (path != NULL)) { //
                test_json = path;
                if (test_json.length() < 20){
                    std::cout << "path = " << test_json << std::endl;
                    std::string content = readContent(request);
                    std::cout << content << std::endl;
                    // sendText(request, 200, "{}");
                    // std::cout << " -----------Received data -----------" << std::endl;

                    try {
                        auto j = json::parse(content);
                        auto crop_frame = j["crop_id"];
                        auto full_frame = j["image_id"];
                        std::string frame;
                        if (crop_frame.empty()){
                                frame = full_frame;
                        }
                        else{
                            frame = crop_frame[0];
                        }
                        auto jObjectId = j["extras"]["object_id"];
                        std::vector<std::string> objectNames;
                        for (size_t i = 0; i < jObjectId.size(); i++) {
                            objectNames.push_back(server->objectManager->objectName[jObjectId[i]]);
                        }
                        
                        auto jLocations = j["extras"]["locations"];
                        std::vector<cv::Rect> locations;
                        for (auto jLocation : jLocations) {
                            cv::Rect box(jLocation[0], jLocation[1], jLocation[2], jLocation[3]);
                            locations.push_back(box);
                        }
                        char timer[25];
                        sprintf(timer, "%02d:%02d:%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                        std::string time= std::string(timer);
                        if (locations.size() > 0) {
                            ObjectEvent* event = new ObjectEvent(cameraId, objectNames , locations, time, frame);
                            server->eventManager->insertObjectEvent(event);
                        }
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                else { //
                // sendText(request, 200, "{}");
                // std::cout << " -----------Received Image -----------" << std::endl;
                    std::string frame;
                    frame = path;
                    std::cout << "frame = " << frame << std::endl;
                    // std::cout << "cameraId " << cameraId << std::endl;
                    // std::cout << "frame =" << frame << std::endl;
                    // cv::Mat image =readImage(request);
                    cv::Mat image;
                        readImage(request, image);
                    // if (cameraId==1){
                    //     std::cout << image.size() << std::endl;
                    // }
                    if (!image.empty()){
                        server->eventManager->updateFrame(frame, image, cameraId);
                    }
                }
            }
            
            
        }
        
       // end
        // else if (startWith(&path, "/frame/")) {
        //     int cameraId;
        //     int frame;
        //     std::string checkId = path ;
            
        //     size_t pos = checkId.find("/");
        //     int id = std::stoi(checkId.substr(0,pos));
        //     if (nextInt(&path, &cameraId) && nextInt(&path, &frame)) {
        //         cv::Mat image = readImage(request);
        //         if (cameraId == 1) {
        //             std::cout << image.size() << std::endl;
        //         } 
        //         if (!image.empty()) {
        //             server->eventManager->updateFrame(frame, image, id);
        //             // if (cameraId == 3){
        //             // cv::imwrite("nameImage.jpg", image);
        //         }
        //             // std::string nameImage = "../datalicense/" + "_" + std::to_string(frame) + ".jpg";
        //             // cv::imwrite("nameImage.jpg", image); 
                
        //     }
        // }
        
        evhttp_uri_free(uri);
    }
    sendText(request, 200, "{}");
}
const std::string HttpServer::readContent(struct evhttp_request* request) {
    std::string content;
    struct evbuffer* buffer;
    buffer = evhttp_request_get_input_buffer(request);
    while (evbuffer_get_length(buffer) > 0) {
        int n;
        char cbuf[1024];
        n = evbuffer_remove(buffer, cbuf, sizeof(cbuf));
        if (n > 0) {
            content += std::string(cbuf, n);
        }
    }
    return content;
}

// const cv::Mat HttpServer::readImage(struct evhttp_request* request) {
//     struct evbuffer* buffer;
//     buffer = evhttp_request_get_input_buffer(request);
//     size_t size = evbuffer_get_length(buffer);
//     if (size > 0) {
//         uint8_t* data = (uint8_t*)malloc(size);
//         if (data != NULL) {
//             int n = evbuffer_remove(buffer, data, size);
//             if (n > 0) {
//                 // decode here
//                 cv::Mat raw(1, n, CV_8UC1, data);
//                 cv::Mat image = cv::imdecode(raw, cv::IMREAD_COLOR);
//                 return image;
//             }
//             free(data);
//         }
//     }
//     std::cout << "anh rong " << std::endl;
//     return cv::Mat();
// }
// void HttpServer::readImage(struct evhttp_request* request, cv::Mat& image) {
//     image.release();
//     struct evbuffer* buffer;
//     buffer = evhttp_request_get_input_buffer(request);
//     size_t size = evbuffer_get_length(buffer);
//     if (size > 0) {
//         uint8_t* data = (uint8_t*)malloc(size);
//         if (data != NULL) {
//             int n = evbuffer_remove(buffer, data, size);
//             if (n > 0) {
//                 // decode here
//                 cv::Mat raw(1, n, CV_8UC1, data);
//                 image = cv::imdecode(raw, cv::IMREAD_COLOR);
//             }
//             free(data);
//         }
//     }
//     else{
//         image = cv::Mat();
//     }
// }
void HttpServer::readImage(struct evhttp_request *request, cv::Mat& image) {
    image.release();
    struct evbuffer *buffer;
    buffer = evhttp_request_get_input_buffer(request);
    size_t size = evbuffer_get_length(buffer);
    std::string search = "Content-Type";
    struct evbuffer_ptr searchPtr =  evbuffer_search(buffer, search.c_str(), search.size(), NULL);
    struct evbuffer_ptr spacePtr = evbuffer_search_eol(buffer, &searchPtr, NULL , EVBUFFER_EOL_ANY);
    search = "----";
    struct evbuffer_ptr endPtr =  evbuffer_search(buffer, search.c_str(), search.size(), &searchPtr);
    evbuffer_ptr_set(buffer, &spacePtr, 4, EVBUFFER_PTR_ADD);
    size_t fileSize =  endPtr.pos - spacePtr.pos - 2;
    if (fileSize > 0) {
        uint8_t* data = (uint8_t*)malloc(fileSize);
        ev_ssize_t readData =  evbuffer_copyout_from(buffer, &spacePtr, data, fileSize);
        if (readData > 0) {
            cv::Mat raw(1, readData, CV_8UC1, data);
            image = cv::imdecode(raw, cv::IMREAD_COLOR);
            // std::cout << image.size() << std::endl;
            // cv::imwrite("testHttp.jpg", image);
        }
        // evbuffer_remove(buffer, data, size);
        free(data);
    }
    else{
        image = cv::Mat();
    }
}

void HttpServer::sendError(struct evhttp_request* request, int status, const std::string& message) {
    json j;
    j["error"] = true;
    j["reason"] = message;
    sendJson(request, status, j);
}

void HttpServer::sendJson(struct evhttp_request* request, int status, const json& j) {
    struct evbuffer* buffer;
    std::string content;
    std::string header;
    buffer = evbuffer_new();
    content = j.dump();
    evbuffer_add(buffer, content.data(), content.size());
    
    evhttp_add_header(request->output_headers, "Content-Type", "application/json");
    evhttp_add_header(request->output_headers, "Content-Length", std::to_string(content.size()).c_str());
    evhttp_send_reply(request, status, NULL, buffer);
    evbuffer_free(buffer);
}

void HttpServer::sendText(struct evhttp_request* request, int status, const std::string& text) {
    struct evbuffer* buffer;
    std::string header;
    buffer = evbuffer_new();
    evbuffer_add(buffer, text.data(), text.size());
    
    evhttp_add_header(request->output_headers, "Content-Type", "text/plain; charset=us-ascii");
    evhttp_add_header(request->output_headers, "Content-Length", std::to_string(text.size()).c_str());
    evhttp_send_reply(request, status, NULL, buffer);
    evbuffer_free(buffer);
}
