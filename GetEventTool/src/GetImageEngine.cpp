#include "GetImageEngine.hpp"

GetImageEngine::GetImageEngine(){
	std::cout << "Constructor GET IMAGE ENGINE " << std::endl;
	this->jsonSession = new HttpSession();
}
GetImageEngine::~GetImageEngine(){
    if (this->jsonSession){ 
        delete this->jsonSession;
        std::cout << "Delete jsonSession" << std::endl; 
    }
	std::cout << "Destructor GetImageEngine" << std::endl;
}
void GetImageEngine::process(){
	std::cout << "ipcamera = " << this->ipcamera << std::endl;
    std::string message = this->getJson();
    // std::cout << "message = " << message << std::endl;
	std::cout << "path = " << this->dirSaveJson << std::endl;
    std::string Time = getTime();
    this->saveJson(this->dirSaveJson, message, Time);
    handleRequest(message);
	this->overrideLastID(this->dirLastEventID, this->lastID);
	std::cout << "Process Events Successfull" << std::endl;
}
int GetImageEngine::loadLastID (std::string& path){
	int lastId;
	this->myfile.open(path, std::ios::in);
	if (this->myfile.is_open()){
		this->myfile >> lastId;
	}
	std::cout << "lastID = " << lastId << std::endl;
	this->myfile.close();
	return lastId; 
}
void GetImageEngine::overrideLastID (std::string& path, int& lastID){
	this->myfile.open(path, std::ios::out | std::ios::trunc);
	if (this->myfile.is_open()){
		this->myfile << lastID;
	}
	this->myfile.close();
}
void GetImageEngine::saveJson(std::string& path, std::string& message, std::string& time){
	this->myfile.open(path, std::ios::out | std::ios::app);
	if (this->myfile.is_open()){
        this->myfile << time;
        this->myfile << "\n";    
        this->myfile << message;
    	this->myfile << "\n";
		this->myfile << "----------------------------------------------done---------------------------------------------\n"; 
    }
    this->myfile.close();
}
std::string GetImageEngine::getTime(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	char timer[70];
	sprintf(timer, "%02d:%02d:%02d:%02d:%02d:%02d", ltm->tm_mday,ltm->tm_mon + 1,ltm->tm_year + 1900 ,ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
	std::string time= std::string(timer);
	return time;
} 
std::string GetImageEngine::get_Token(const std::string& ipcamera,const std::string& username,const std::string& userpwd){
    std::string url_login = "https://" + ipcamera + ":4004/api/login";
    std::cout << "[LOG]  " << url_login << std::endl;
    json j;
    j["username"] = username;
    j["userpwd"] = userpwd;
    std::string content = j.dump();
	HttpSession* get_token = new HttpSession();
	get_token->addHeader("Content-Type: application/json");
	get_token->setMethod("POST");
	get_token->setUrl(url_login);
	get_token->setPostString(content);
	get_token->start();
	std::string message((const char *)get_token->getData(), get_token->getSize());
    // std::cout << "[LOG]  Response of Camera: " << message << std::endl;
	auto j1 = json::parse(message);
	std::string access_token;
	if (message != "[]"){
		access_token = j1["access_token"];
		std::cout << "[LOG]  ACCESS_TOKEN: "<< access_token << std::endl; 
	}
	delete get_token;
    return access_token;
}
int GetImageEngine::convertTimeStamp(std::string& time)
{
    std::tm t{};
    std::istringstream ss(time);
    try
    {
        ss >> std::get_time(&t, "%Y-%m-%dT%H:%M:%S");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    if (ss.fail())
    {
        throw std::runtime_error{"failed to parse time string"};
        return 0;
    }
    else
    {
        return std::mktime(&t);
    }
}

void GetImageEngine::getImage(std::string& currentFrameUrl){
	this->imageSession = new HttpSession();
	this->imageSession->addHeader("Content-Type: image/jpeg");
    this->imageSession->setUrl(currentFrameUrl);
    this->imageSession->start();
	try {
		std::string dataImage((const char *)imageSession->getData(), imageSession->getSize());
		std::vector<uchar> uImage(dataImage.begin(), dataImage.end());
		this->imageEvent.clone();
		this->imageEvent = cv::imdecode(uImage, cv::IMREAD_COLOR);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
    delete this->imageSession;
	this->imageSession = nullptr;
}
std::string GetImageEngine::getJson(){
	this->jsonSession->setUrl(this->urlJson);
    this->jsonSession->addHeader("Content-Type: application/json");
    this->jsonSession->start();
	std::string message;
    try {
    	std::string message1((const char *)jsonSession->getData(), jsonSession->getSize());  
		message = message1;  
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
	return message;
}
void GetImageEngine::drawBox(){
	for (auto box: this->boxes) {
		// std::cout << "afdasf" << std::endl;
        cv::rectangle(this->imageEvent, box, cv::Scalar(0, 255, 0), 4);
    }  
}
void GetImageEngine::writeImage(std::string& nameImage){
	if (!this->imageEvent.empty()){
		cv::imwrite(nameImage, this->imageEvent);
		std::cout << "--------writed done--------" << std::endl;
	}
}

void GetImageEngine::extractInformation(std::string& message, int& i){
	auto j = json::parse(message);
	auto jlocations = j[i]["extras"]["objects"];
	for (auto jlocations1 : jlocations){
		auto p1 = jlocations1["locations"];
		cv::Rect box(p1[0], p1[1], p1[2], p1[3]);
		this->boxes.push_back(box);
	}  
	this->eventID = j[i]["eventId"];
	this->timeEvent = j[i]["time"];
	std::cout <<" eventId = " << j[i]["eventId"] << std::endl;
	std::string imageID = j[i]["image_id"];
	std::cout << "imageID = "<< imageID << std::endl;
	this->currentFrameUrl = this->urlFrame + imageID + "?access_token=" + this->access_token;
	// std::cout << currentFrameUrl << std::endl;
}