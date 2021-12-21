#include "GetImageEngine.hpp"

GetImageEngine::GetImageEngine(){

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
    get_token->~HttpSession();
    return access_token;
}
GetImageEngine::~GetImageEngine(){
    
}