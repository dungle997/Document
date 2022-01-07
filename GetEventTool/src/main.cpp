#include <iostream>
#include "json.h"
#include "HttpSession.hpp"
// #include "CountEvent.hpp"
// #include "FaceDetectProcessor.hpp"
#include "FaceMaskProcessor.hpp"
#include "FaceProcessor.hpp"
#include "FireProcessor.hpp"
#include "LicenseProcessor.hpp"
// #include "ObjectProcessor.hpp"
#include "DistancingProcessor.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include "CountProcessor.hpp"
#include "Load.hpp"
#include "GlobalConfig.hpp"
#include "HttpSession.hpp"

LoadProcessor* loadProcessor = NULL;

int main(){
    config.load();
    loadProcessor = new LoadProcessor();
    loadProcessor->load();
    return 0;

}