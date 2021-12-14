//
//  PathHelper.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 17/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "../LoadProcessor/GlobalConfig.hpp"
#include "PathHelper.hpp"

std::string PathHelper::makePath(const std::string filename) {
    std::string path = config.profilePath;
    path += filename;
    return path;
}


//int ret;
//pid_t pid;
//char pathbuf[PROC_PIDPATHINFO_MAXSIZE];
//
//pid = getpid();
//ret = proc_pidpath(pid, pathbuf, sizeof(pathbuf));
//if ( ret <= 0 ) {
//    fprintf(stderr, "PID %d: proc_pidpath ();\n", pid);
//    fprintf(stderr, "    %s\n", strerror(errno));
//} else {
//    printf("proc %d: %s\n", pid, pathbuf);
//}
