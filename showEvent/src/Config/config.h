

//
//  config.h
//  CamHub
//
//  Created by Pham Quang Hoa on 21/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef config_h
#define config_h

// Profiles

#ifdef __APPLE__
#define MAC_HOAPQ
#else
#define AIO
#endif

#ifdef MAC_HOAPQ

#define DATA_PATH   "/Volumes/Data/Temp/camhubdata/"
#define FULLSCREEN  false
#define RESOLUTION   2   // 1: FullHD, 2: 4K

#define CAM_LINK_1  "rtsp://192.168.1.112:8900/live"
#define CAM_LINK_2  "rtsp://192.168.1.112:8900/live"
#define CAM_LINK_3  "rtsp://admin:Bkav2019@192.168.1.11:554"
#define CAM_LINK_4  "rtsp://admin:Bkav2019@192.168.1.12:554"

#endif

#ifdef AIO

#define DATA_PATH   "/home/a/data/"
#define FULLSCREEN  true
#define RESOLUTION   2   // 1: FullHD, 2: 4K
#define WEBSOCKET_PORT 8080

#define CAM_LINK_1  "rtsp://10.2.64.7:8900/live"
#define CAM_LINK_2  "rtsp://10.2.64.53:8900/live"
//#define CAM_LINK_3  "rtsp://10.2.64.197:8900/live"
//#define CAM_LINK_3  "rtsp://172.36.68.11:8900/live"
//#define CAM_LINK_3 "rtsp://10.2.64.5:8554/demo.ts"
#define CAM_LINK_3   "rtsp://172.36.68.10:8900/live"
#define CAM_LINK_4  "rtsp://172.36.68.11:8900/live"
#define CAM_LINK_5  "rtsp://10.2.64.211:8900/live"
#define CAM_LINK_6  "rtsp://10.2.64.53:8900/live"
#define FONT_PATH   "../Config/demofont.ttf"
#define CONFIG_JSON_PATH  "../Config/config.json"
#define AIVIEW_ICON_PATH  "../Config/icon.png"

#endif

#endif /* config_h */
