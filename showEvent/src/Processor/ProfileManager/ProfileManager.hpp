//
//  ProfileManager.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef ProfileManager_hpp
#define ProfileManager_hpp

#include <map>
#include "Profile.hpp"

class ProfileManager {
private:
    std::string pathProfile;
public:
    ProfileManager();
    ~ProfileManager();
    
    void load();
    
    std::map<std::string, Profile*> profiles;
};

#endif /* ProfileManager_hpp */
