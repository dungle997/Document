//
//  CountProcessor.cpp
//  CamHub
//
//  Created by Pham Quang Hoa on 19/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#include "TrafficProcessor.hpp"

TrafficProcessor::TrafficProcessor(int cameraId, DisplayBoard *displayBoard, int index, EventManager *eventManager)
{
    this->cameraId = cameraId;
    this->displayBoard = displayBoard;
    this->index = index;
    this->eventManager = eventManager;
}

TrafficProcessor::~TrafficProcessor()
{
}

void TrafficProcessor::process(Mat &frame)
{
    int h = 240;
    int w = 427;

    TrafficEvent *lastEvent = NULL;

    int viewIndex = 0;
    for (int index = 0; index < this->eventManager->trafficEvent.size(); index++)
    {
        TrafficEvent *event = this->eventManager->trafficEvent[index];
        if (event->cameraId == this->cameraId && !event->image.empty())
        {
            if (lastEvent == NULL)
            {
                lastEvent = event;
            }

            if (viewIndex < 1)
            {
                cv::Rect roi(frame.cols - w - 24, 24 + (24 + h) * viewIndex, w, h);
                Mat dst = frame(roi);
                cv::resize(event->image, dst, cv::Size(w, h));
                viewIndex++;
            }
        }
    }

    // Number of people
    int countTraffic = 0;
    if (lastEvent != NULL)
    {
        countTraffic = lastEvent->countTraffic;
    }

    std::string titleTraffic = "Vehicle: " + std::to_string(countTraffic);

    double fontScale = 2;
    int fontFace = cv::FONT_HERSHEY_DUPLEX;
    int thickness = 6;
    const char *text = titleTraffic.c_str();
    cv::Size textSize = getTextSize(text, fontFace, fontScale, thickness, 0);

    int tx = (frame.cols - textSize.width) / 2;
    int ty = 70;

    cv::putText(frame, text, cv::Point(tx + 1 + 30, ty + 1 + 30), fontFace, fontScale, cv::Scalar(0, 67, 255), thickness);
    cv::putText(frame, text, cv::Point(tx+30, ty + 30), fontFace, fontScale, cv::Scalar(0, 70, 255), thickness);
    this->displayBoard->put(frame, this->index);
}
