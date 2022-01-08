#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
#include "DistancingProcessor.hpp"
#include <fstream>
#include <ctime>

DistancingProcessor::DistancingProcessor() : GetImageEngine(){

}
DistancingProcessor::~DistancingProcessor(){

}
void DistancingProcessor::handleRequest(std::string& message){
    std::cout << "Get Distancing Event" << std::endl;
    auto j = json::parse(message);
    if (message != "[]"){
        std::cout << "j.size() = " << j.size() << std::endl;
        for (int i = j.size() - 1; i > -1; i--) {
            extractInformation(message, i);
            auto jDistances = j[i]["extras"]["distancing"];
            for (auto jdistancing : jDistances){
                std::vector<float> temp;
                for (auto id : jdistancing){
                    temp.push_back(id);
                }
                this->distances.push_back(temp);
            }
            this->getImage(this->currentFrameUrl);
            // drawBox();
            drawBoxDistancing(this->imageEvent);
            std::string name = nameImage();
            writeImage(name);
            this->boxes.clear();
            this->distances.clear();
        }
        std::cout << "lastId new = "<< j[0]["eventId"] << std::endl;
        this->lastID = j[0]["eventId"];
    } 
}
std::string DistancingProcessor::nameImage(){
    std::string nameImage = "../Event/" + this->ipcamera + "/socialdistancing/" + this->timeEvent + "_" + std::to_string(this->eventID) + ".jpg";
    return nameImage;
}
float rounding(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
void DistancingProcessor::drawBoxDistancing(cv::Mat& image){
    double fontScale = 2;
    int baseLine;
    int fontFace = cv::FONT_HERSHEY_DUPLEX;
    int thickness = 4;
    // Draw box
    if (this->boxes.size() != 0) {
        for (auto distance : distances) {
            int tx = boxes[(int)distance[0] - 1].x;
            int ty = boxes[(int)distance[0] - 1].y - 10;
            cv::putText(this->imageEvent, std::to_string((int)distance[0]), cv::Point(tx, ty), fontFace, fontScale, cv::Scalar(0, 255, 0), thickness);

            tx = boxes[(int)distance[1] - 1].x;
            ty = boxes[(int)distance[1] - 1].y - 10;
            cv::putText(this->imageEvent, std::to_string((int)distance[1]), cv::Point(tx, ty), fontFace, fontScale, cv::Scalar(0, 255, 0), thickness);

            distance[2] = distance[2];
            std::stringstream distancing;
            distancing << rounding(distance[2]);
            std::string text = distancing.str() + " m";

            int id0 = (int)(distance[0] - 1);
            int id1 = (int)(distance[1] - 1);
            cv::rectangle(this->imageEvent, boxes[id0], cv::Scalar(0, 255, 0), 4);
            cv::rectangle(this->imageEvent, boxes[id1], cv::Scalar(0, 255, 0), 4);
            cv::Point centerBox1((int)(boxes[id0].x + boxes[id0].width / 2), (int)(boxes[id0].y + boxes[id0].height / 2));
            cv::Point centerBox2((int)(boxes[id1].x + boxes[id1].width / 2), (int)(boxes[id1].y + boxes[id1].height / 2));

            if (distance[2] > 2.00) {
                cv::line(this->imageEvent, centerBox1, centerBox2, cv::Scalar(0, 255, 0), 4);
            }
            else {
                cv::line(this->imageEvent, centerBox1, centerBox2, cv::Scalar(0, 0, 255), 4);
            }
            int txDis;
            int tyDis;
            if (centerBox1.x < centerBox2.x) {
                txDis = centerBox1.x + (centerBox2.x - centerBox1.x) / 2;
                tyDis = centerBox1.y + (centerBox2.y - centerBox1.y) / 2 - 10;
            }
            else {
                txDis = centerBox2.x + (centerBox1.x - centerBox2.x) / 2;
                tyDis = centerBox2.y + (centerBox1.y - centerBox2.y) / 2 - 10;
            }
            cv::putText(this->imageEvent, text, cv::Point(txDis, tyDis), fontFace, fontScale, cv::Scalar(0, 67, 255), 2);
            cv::Size textTimeSize = cv::getTextSize(this->timeEvent, cv::FONT_HERSHEY_TRIPLEX, 2, 3, 0);
            cv::putText(this->imageEvent, this->timeEvent, cv::Point(this->imageEvent.cols - textTimeSize.width - 30, 40 + textTimeSize.height), cv::FONT_HERSHEY_TRIPLEX, 2, cv::Scalar(0, 67, 255), 3);
        }
    }
}

