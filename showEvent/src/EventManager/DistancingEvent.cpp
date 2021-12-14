//
//  DistancingEvent.cpp
//  CamHub
//
//  Created by Nguyen Xuan Truong on 29/07/2020.
//  Copyright © 2020 Nguyen Xuan Truong. All rights reserved.
//


#include "DistancingEvent.hpp"

DistancingEvent::DistancingEvent(int cameraId, const std::vector<cv::Rect>& boxes, const std::vector<std::vector<float>>& distances ,const std::string& time, const std::string& date, std::string frame) {
    this->cameraId = cameraId;
    this->boxes = boxes;
    this->distances = distances;
    this->time = time;
    this->date = date;
    this->frame = frame;
}

DistancingEvent::~DistancingEvent() {
    
}

float rounding(float var)  { 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
} 

void DistancingEvent::update(const cv::Mat& image) {
    this->image = image;
    double fontScale = 2;
    int baseLine;
    int fontFace = cv::FONT_HERSHEY_DUPLEX;
    int thickness = 4;
    // Draw box
    if (this->boxes.size() != 0) {
        for (auto distance: distances) {
                int tx = boxes[(int) distance[0] - 1].x;
                int ty = boxes[(int) distance[0] - 1].y - 10;
                cv::putText(this->image, std::to_string((int) distance[0]), cv::Point(tx, ty), fontFace, fontScale, cv::Scalar(0, 255, 0), thickness);

                tx = boxes[(int) distance[1] - 1].x;
                ty = boxes[(int) distance[1] - 1].y - 10;
                cv::putText(this->image, std::to_string((int) distance[1]), cv::Point(tx, ty), fontFace, fontScale, cv::Scalar(0, 255, 0), thickness);
                
                //distance[2] = distance[2]/1000;
                std::stringstream distancing;
                distancing << rounding(distance[2]);
                std::string text = distancing.str() + " m"; 

                int id0 = (int) (distance[0] -1);
                int id1 = (int) (distance[1] - 1);
                cv::rectangle(this->image, boxes[id0], cv::Scalar(0, 255, 0), 4);
                cv::rectangle(this->image, boxes[id1], cv::Scalar(0, 255, 0), 4);
                cv::Point centerBox1( (int) (boxes[id0].x +boxes[id0].width/2),(int) (boxes[id0].y + boxes[id0].height / 2));
                cv::Point centerBox2((int) (boxes[id1].x +boxes[id1].width/2), (int) (boxes[id1].y + boxes[id1].height / 2));

                if ( distance[2] > 2.00) {
                    cv::line(this->image, centerBox1, centerBox2,  cv::Scalar(0, 255, 0), 4);
                } else
                {
                    cv::line(this->image, centerBox1, centerBox2,  cv::Scalar(0, 0, 255), 4);
                }
                
                int txDis;
                int tyDis;
                if (centerBox1.x < centerBox2.x) {
                    txDis = centerBox1.x + (centerBox2.x-centerBox1.x)/2;
                    tyDis = centerBox1.y + (centerBox2.y - centerBox1.y)/2 -10 ;
                } else
                {
                    txDis = centerBox2.x + (centerBox1.x-centerBox2.x)/2;
                    tyDis = centerBox2.y + (centerBox1.y - centerBox2.y)/2 -10;
                }
                cv::putText(this->image, text, cv::Point(txDis, tyDis), fontFace, fontScale, cv::Scalar(0, 67, 255), 2);

                // add date time and model

                // std::string textDateTime = time + " " + date;

                // cv::Size textModelSize = cv::getTextSize("AI View S213", cv::FONT_HERSHEY_TRIPLEX, 2, 3, 0);
                // cv::Size textTimeSize = cv::getTextSize(textDateTime, cv::FONT_HERSHEY_TRIPLEX, 2, 3, 0);

                // cv::putText(this->image, "AI View S213", cv::Point(25, 40 + textModelSize.height), cv::FONT_HERSHEY_TRIPLEX, 2, cv::Scalar(0, 67, 255), 3);
                // cv::putText(this->image, textDateTime, cv::Point(this->image.cols - textTimeSize.width - 30, 40 + textModelSize.height), cv::FONT_HERSHEY_TRIPLEX, 2, cv::Scalar(0, 67, 255), 3);
                
                // if (this->boxes.size()>1) {
                //     std::string nameImg = "data/" + std::to_string(frame)+".jpg";
                //     cv::imwrite(nameImg, this->image);
                // }


                 cv::Size textTimeSize = cv::getTextSize(this->time, cv::FONT_HERSHEY_TRIPLEX, 2, 3, 0);

                cv::putText(this->image, this->time, cv::Point(this->image.cols - textTimeSize.width - 30, 40 + textTimeSize.height), cv::FONT_HERSHEY_TRIPLEX, 2, cv::Scalar(0, 67, 255), 3);
                
        }
    }
}
