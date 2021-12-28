#include "GetImageEngine.hpp"

GetImageEngine::GetImageEngine(){

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
    std::cout << "[LOG]  Response of Camera: " << message << std::endl;
	auto j1 = json::parse(message);
	std::string access_token;
	if (message != "[]"){
		access_token = j1["access_token"];
		std::cout << "[LOG]  ACCESS_TOKEN: "<< access_token << std::endl; 
	}
	delete get_token;
    return access_token;
}
GetImageEngine::~GetImageEngine(){
    
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