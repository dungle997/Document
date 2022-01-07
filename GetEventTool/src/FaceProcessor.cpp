
#include "FaceProcessor.hpp"

FaceProcessor::FaceProcessor() : GetImageEngine(){

}
FaceProcessor::~FaceProcessor(){

}
// void FaceProcessor::process(const std::string& ipcamera, const std::string& username, const std::string& userpwd) {
//     std::string ipCam = ipcamera;
//     this->access_token = GetImageEngine::get_Token(ipcamera, username, userpwd);
//     std::cout << "ipcamera = " << ipcamera << std::endl;
//     int lastId =1;
//     /**/

//     std::ifstream file1;
//     file1.open("../Data_EventId/" + ipcamera + "/face.txt", std::ios::in);
//     if(file1.is_open()){
//         file1 >> lastId;
//         std::cout << "lastId = " << lastId <<std::endl; 
//     }
//     file1.close();
//     /**/
//     std::string urlJson = "http://" + ipCam + ":4003/event/facerecognize?lastId="+ std::to_string(lastId)+ "&count=300";
//     std::string urlFrame = "http://"+ ipCam + ":4003/event/frame/facerecognize/";
//     HttpSession* jsonSession = new HttpSession();
//     std::fstream myfile;
//     time_t now = time(0);
//     tm *ltm = localtime(&now);
//     char timer[70];
//     sprintf(timer, "%02d:%02d:%02d:%02d:%02d:%02d", ltm->tm_mday,ltm->tm_mon + 1,ltm->tm_year + 1900 ,ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
//     std::string Time= std::string(timer);
//     // std::string day = std::to_string(ltm->tm_mday) + "-" + std::to_string(ltm->tm_mon);
//     //
//     std::string path = "../Json_Event/" + ipcamera +"/face.txt";
//     //
//     jsonSession->setUrl(urlJson);
//     jsonSession->addHeader("Content-Type: application/json");
//     jsonSession->start();

//     try {
//         std::string message((const char *)jsonSession->getData(), jsonSession->getSize());
//         auto j = json::parse(message);
//         myfile.open(path, std::ios::out | std::ios::app);
//         if (myfile.is_open()){
//         myfile << Time;
//         myfile << "\n";    
//         myfile << message;
//         myfile << "\n"; 
//         }
//         myfile.close();
//         if (message != "[]"){
//             for (auto event : j) {
//                 int monitorId = event["monitor_id"];
//                 auto jlocations = event["locations"];
//                 auto profileId = event["profileId"];
//                 std::vector<cv::Rect> boxes;
//                 for (auto jlocation : jlocations) {
//                     cv::Rect box(jlocation[0], jlocation[1], jlocation[2], jlocation[3]);
//                     boxes.push_back(box);
//                 }

//                 // auto jdistances = event["distancing"];
//                 // std::vector<std::vector<float>> distances;
//                 // for(auto jdistance : jdistances) {
//                 //     std::vector<float> distance;
//                 //     for (auto id : jdistance) {
//                 //         distance.push_back(id);
//                 //     }
//                 //     distances.push_back(distance);
//                 // }
//                 /**/
//                 int eventId = event["eventId"];
//                 /**/
//                 std::cout << "eventId = "<<eventId << std::endl;
//                 std::string time = event["time"];
//                 time.replace(time.find(" "), 1, "_");
//                 // int frame = event["frame"];
            
//                     std::cout << "--------Face Recognize Event-------" << std::endl;
//                     FaceEvent* newEvent = new FaceEvent(monitorId, profileId, boxes, time, eventId, ipcamera);
//                     std::string currentFrameUrl = urlFrame +  std::to_string(eventId);
//                     HttpSession* imageSession = new HttpSession();
//                     imageSession->addHeader("Content-Type: image/jpeg");
//                     imageSession->setUrl(currentFrameUrl);
//                     imageSession->start();
//                     try {
//                         std::string dataImage((const char *)imageSession->getData(), imageSession->getSize());
//                         std::vector<uchar> uImage(dataImage.begin(), dataImage.end());
//                         cv::Mat image = cv::imdecode(uImage, cv::IMREAD_COLOR);
//                         newEvent->update(image);
//                     }
//                     catch(const std::exception& e) {
//                         std::cerr << e.what() << '\n';
//                     }
//                     delete imageSession;
//                     delete newEvent;
                
//             }
//             /**/
//             std::ofstream file;
//             file.open("../Data_EventId/" + ipcamera + "/face.txt");
//                     if(file.is_open()){
//                         file << j[j.size()-1]["eventId"] << std::endl;
//                         std::cout << j[j.size()-1]["eventId"] << std::endl;
//                     }   
                
//             file.close(); 
//             /**/ 
//         }
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     std::cout << "Process Events Successfull" << std::endl;
//     delete jsonSession;
// }
void FaceProcessor::handleRequest(std::string& message){
    std::cout << "Get Face Event" << std::endl;
    auto j = json::parse(message);
    if (message != "[]"){
        std::cout << "j.size() = " << j.size() << std::endl;
        for (int i = j.size() - 1; i > -1; i--) {
            extractInformation(message, i);
            auto jprofileId = j[i]["extras"]["objects"];
            for (auto jprofileid1 : jprofileId){
                auto profileId2 = jprofileid1["profileId"];
                this->profileId.push_back(profileId2);
            }
            this->getImage(this->currentFrameUrl);
            drawBox();
            std::string name = nameImage();
            writeImage(name);
            this->boxes.clear();
            this->profileId.clear();
        }
        std::cout << "lastId new = "<< j[0]["eventId"] << std::endl;
        this->lastID = j[0]["eventId"];
    } 
}
std::string FaceProcessor::nameImage(){
    std::string name ="";
    for (auto profile : profileId){
        name = name + profile + "_";
    }
    std::string nameImage = "../Event/" + this->ipcamera + "/facerecognize/" + name + "_"+this->timeEvent + "_" + std::to_string(this->eventID) + ".jpg";
    return nameImage;
}

