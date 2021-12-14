//
//  PathHelper.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef PathHelper_hpp
#define PathHelper_hpp

#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>

class PathHelper {
public:
    static std::string makePath(const std::string filename);
    static std::string loadPath();    
};

#endif /* PathHelper_hpp */
