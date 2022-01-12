

#ifndef LoadProcessor_hpp
#define LoadProcessor_hpp

#include "GlobalConfig.hpp"
#include "CountProcessor.hpp"
// #include "FaceDetectProcessor.hpp"
#include "FaceMaskProcessor.hpp"
#include "FaceProcessor.hpp"
#include "DistancingProcessor.hpp"
#include "FireProcessor.hpp"
#include "LicenseProcessor.hpp"
// #include "ObjectProcessor.hpp"
#include <sys/stat.h>


class LoadProcessor {
public:
    LoadProcessor();
    ~LoadProcessor();
    void load();
    void setParam(std::string& type, GetImageEngine* obj, std::string& ipcamera, std::string& username, std::string& userpwd, std::string& port, std::string& loadID);
private: 
    GetImageEngine* LoadSubClass(std::string& type, GetImageEngine* obj);
    bool IsPathExist(const std::string &s);
    void CheckPathExist(std::string& type, GetImageEngine* obj);

};

#endif