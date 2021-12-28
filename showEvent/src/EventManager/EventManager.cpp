//
//  EventManager.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 18/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "EventManager.hpp"

#define MAX_FACE_EVENT  20
#define MAX_UNKNOWN_FACE_EVENT  20
#define MAX_COUNT_EVENT 10
#define MAX_LICENSE_EVENT   10

EventManager::EventManager() {
    
}

EventManager::~EventManager() {
    
}

void EventManager::insertFaceEvent(FaceEvent* event) {
    bool isOldEvent = false;
    if (this->faceEvents.size() > 0){
        FaceEvent* eventFirst = this->faceEvents.front(); 
        if (eventFirst->profileId == event->profileId){
            isOldEvent = true;
            this->faceEvents.erase(this->faceEvents.begin());
            this->faceEvents.insert(this->faceEvents.begin(), event);
        }
        // this->faceEvents.insert(this->faceEvents.begin(), event);
        //  if (this->faceEvents.size() > 1) {
            // if (this->faceEvents[0]->profileId == this->faceEvents[1]->profileId) {
            //     this->faceEvents.erase(this->faceEvents.begin() + 1);
    // }
    }
    else if (isOldEvent == false){
        this->faceEvents.insert(this->faceEvents.begin(), event);
    }
    while (this->faceEvents.size() > MAX_FACE_EVENT) {
        FaceEvent* last = this->faceEvents.back();
        this->faceEvents.pop_back();
        delete last;
    }
}

void EventManager::clearFaceEvent() {
    this->faceEvents.clear();
}

void EventManager::clearFaceMaskEvent() {
    this->faceMaskEvents.clear();
}

void EventManager::insertUnknownFaceEvent(UnknownFaceEvent* event) {
    this->unknownFaceEvents.insert(this->unknownFaceEvents.begin(), event);
    while (this->unknownFaceEvents.size() > MAX_UNKNOWN_FACE_EVENT) {
        UnknownFaceEvent* last = this->unknownFaceEvents.back();
        this->unknownFaceEvents.pop_back();
        delete last;
    }
}
void EventManager::insertAlarmEvent(AlarmEvent* event) {
    this->alarmEvents.insert(this->alarmEvents.begin(), event);
    while (this->alarmEvents.size() > MAX_UNKNOWN_FACE_EVENT) {
        AlarmEvent* last = this->alarmEvents.back();
        this->alarmEvents.pop_back();
        delete last;
    }
}

void EventManager::insertCountEvent(CountEvent* event) {
    this->countEvents.insert(this->countEvents.begin(), event);
    while (this->countEvents.size() > MAX_COUNT_EVENT) {
        CountEvent* last = this->countEvents.back();
        this->countEvents.pop_back();
        delete last;
    }
}

void EventManager::insertCowEvent(CowEvent* event) {
    this->cowEvents.insert(this->cowEvents.begin(), event);
    while (this->cowEvents.size() > MAX_COUNT_EVENT) {
        CowEvent* last = this->cowEvents.back();
        this->cowEvents.pop_back();
        delete last;
    }
}

void EventManager::insertFaceDetectEvent(FaceDetectEvent* event) {
    this->faceDetectEvents.insert(this->faceDetectEvents.begin(), event);
    while (this->faceDetectEvents.size() > MAX_COUNT_EVENT) {
        FaceDetectEvent* last = this->faceDetectEvents.back();
        this->faceDetectEvents.pop_back();
        delete last;
    }
}

void EventManager::insertLicenseEvent(LicenseEvent* event) {

    const std::string license_plate = event->number; 
    bool isOldEvent = false;
    for (auto event: this->licenseEvents) {
        if (event->number == license_plate){
            isOldEvent = true;
            break;
        }
        
    }
    if (isOldEvent == false)
        this->licenseEvents.insert(this->licenseEvents.begin(), event);

    while (this->licenseEvents.size() > MAX_LICENSE_EVENT) {
        LicenseEvent* last = this->licenseEvents.back();
        this->licenseEvents.pop_back();
        delete last;
    }
    std::cout << "license.size() = " << licenseEvents.size() << std::endl;
}

void EventManager::insertTraffic(TrafficEvent* event) {
    this->trafficEvent.insert(this->trafficEvent.begin(), event);
    while (this->trafficEvent.size() > MAX_COUNT_EVENT) {
        TrafficEvent* last = this->trafficEvent.back();
        this->trafficEvent.pop_back();
        delete last;
    }
}

void EventManager::insertDistancing(DistancingEvent* event) {
    this->distancingEvents.insert(this->distancingEvents.begin(), event);
    while (this->distancingEvents.size() > MAX_COUNT_EVENT) {
        DistancingEvent* last = this->distancingEvents.back();
        this->distancingEvents.pop_back();
        delete last;
    }
}

void EventManager::insertFaceMaskEvent(FaceMaskEvent* event) {
    this->faceMaskEvents.insert(this->faceMaskEvents.begin(), event);
    while (this->faceMaskEvents.size() > MAX_FACE_EVENT) {
        FaceMaskEvent* last = this->faceMaskEvents.back();
        this->faceMaskEvents.pop_back();
        delete last;
    }
}

void EventManager::insertNoFaceMaskEvent(NoFaceMaskEvent* event) {
    this->noFaceMaskEvents.insert(this->noFaceMaskEvents.begin(), event);
    while (this->noFaceMaskEvents.size() > MAX_UNKNOWN_FACE_EVENT) {
        NoFaceMaskEvent* last = this->noFaceMaskEvents.back();
        this->noFaceMaskEvents.pop_back();
        delete last;
    }
}

void EventManager::insertFireEvent(FireEvent* event) {
    this->fireEvents.insert(this->fireEvents.begin(), event);
    while (this->fireEvents.size() > MAX_COUNT_EVENT) {
        FireEvent* last = this->fireEvents.back();
        this->fireEvents.pop_back();
        delete last;
    }
}

void EventManager::insertObjectEvent(ObjectEvent* event) {
    this->objectEvents.insert(this->objectEvents.begin(), event);
    while (this->objectEvents.size() > MAX_COUNT_EVENT) {
        ObjectEvent* last = this->objectEvents.back();
        this->objectEvents.pop_back();
        delete last;
    }
}


void EventManager::updateFrame(std::string frame, const cv::Mat& image, int cameraId) {
    // Update face events
    // Nothing to do
    
    for (auto event: this->faceMaskEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }

    for (auto event: this->noFaceMaskEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }

    for (auto event: this->faceEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }
    for (auto event: this->alarmEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }

    // Update unknown face events
    for (auto event: this->unknownFaceEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }
    
    // Update count event
    for (auto event: this->countEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }

    for (auto event: this->cowEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }
    
    // Update license event
    for (auto event: this->licenseEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
            // std::string nameImage = std::to_string(frame) + ".jpg";
            // cv::imwrite("nameImage.jpg", image);
        }
    }

    for (auto event: this->trafficEvent) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }

    for (auto event: this->fireEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }

    for (auto event: this->distancingEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }

    for (auto event: this->objectEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }
    for (auto event: this->faceDetectEvents) {
        if (event->frame == frame && event->cameraId == cameraId) {
            event->update(image);
        }
    }

}
