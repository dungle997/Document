//
//  EventManager.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 18/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef EventManager_hpp
#define EventManager_hpp

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "FaceEvent.hpp"
#include "AlarmEvent.hpp"
#include "UnknownFaceEvent.hpp"
#include "CountEvent.hpp"
#include "CowEvent.hpp"
#include "LicenseEvent.hpp"
#include "TrafficEvent.hpp"
#include "DistancingEvent.hpp"
#include "FaceMaskEvent.hpp"
#include "NoFaceMaskEvent.hpp"
#include "FireEvent.hpp"
#include "ObjectEvent.hpp"
#include "FaceDetectEvent.hpp"

class EventManager {
public:
    EventManager();
    ~EventManager();
    
    void insertFaceEvent(FaceEvent* event);
    void insertUnknownFaceEvent(UnknownFaceEvent* event);
    void insertCountEvent(CountEvent* event);
    void insertLicenseEvent(LicenseEvent* event);
    void insertTraffic(TrafficEvent* event);
    void insertDistancing(DistancingEvent* event);
    void insertFaceMaskEvent(FaceMaskEvent* event);
    void insertNoFaceMaskEvent(NoFaceMaskEvent* event);
    void insertFireEvent(FireEvent* event);
    void insertObjectEvent(ObjectEvent* event);
    void insertFaceDetectEvent(FaceDetectEvent* event);
    void insertCowEvent(CowEvent* event);
    void insertAlarmEvent(AlarmEvent* event);

    void updateFrame(std::string frame, const cv::Mat& image, int cameraId);
    void clearFaceEvent();
    void clearFaceMaskEvent();
    
    std::vector<FaceEvent*> faceEvents;
    std::vector<UnknownFaceEvent*> unknownFaceEvents;
    std::vector<CountEvent*> countEvents;
    std::vector<LicenseEvent*> licenseEvents;
    std::vector<TrafficEvent*> trafficEvent;
    std::vector<DistancingEvent*> distancingEvents;
    std::vector<FaceMaskEvent*> faceMaskEvents;
    std::vector<NoFaceMaskEvent*> noFaceMaskEvents;
    std::vector<FireEvent*> fireEvents;
    std::vector<ObjectEvent*> objectEvents;
    std::vector<FaceDetectEvent*> faceDetectEvents;
    std::vector<CowEvent*> cowEvents;
    std::vector<AlarmEvent*> alarmEvents;
};

#endif /* EventManager_hpp */
