//
//  Profile.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef Profile_hpp
#define Profile_hpp

#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/freetype.hpp>
#include "../../Config/config.h"

class Profile {
public:
    Profile(std::string id, const std::string name, const std::string position, const cv::Mat portrait);
    ~Profile();
    
    std::string id;
    std::string name;
    std::string position;
    cv::Mat portrait;
    cv::Mat mini;
};

#endif /* Profile_hpp */
