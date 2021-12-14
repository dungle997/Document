//
//  LoadProcessor.hpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 04/11/2020.
//  Copyright © 2019 Nguyen Xuan Truong. All rights reserved.
//

#ifndef LoadProcessor_hpp
#define LoadProcessor_hpp

#include "GlobalConfig.hpp"
#include "../../Render/DisplayBoard.hpp"
#include "../../Render/RtspThread.hpp"
#include "../DisplayProcessor.hpp"
#include "../FaceProcessor.hpp"
#include "../CountProcessor.hpp"
#include "../LicenseProcessor.hpp"
#include "../DistancingProcessor.hpp"
#include "../FaceMaskProcessor.hpp"
#include "../Processor.hpp"
#include "../FireProcessor.hpp"
#include "../ObjectProcessor.hpp"
#include "../../EventManager/EventManager.hpp"
#include "../ProfileManager/ProfileManager.hpp"
#include "../ObjectManager/ObjectManager.hpp"
#include "../FaceDetectProcessor.hpp"
#include "../WelcomeSceenProcessor.hpp"
#include "../CowProcessor.hpp"
#include "../AlarmProcessor.hpp"

class LoadProcessor {
private:
    DisplayBoard* displayBoard;
    EventManager* eventManager;
public:
    LoadProcessor(DisplayBoard* displayBoard, EventManager* eventManager);
    ~LoadProcessor();
    void load();
};

#endif