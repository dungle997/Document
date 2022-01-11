#include <sys/stat.h>
#include <iostream>
bool IsPathExist(const std::string &s)
{
  struct stat buffer;
  return (stat (s.c_str(), &buffer) == 0);
}

int main(){
	std::string dir = "../12/13";	
	if (IsPathExist(dir)){
		std::cout << "Folder Exist" << std::endl;
	}
	else 
		std::cout << "Folder doesn't Exist" << std::endl;	 
	return 0;
}


