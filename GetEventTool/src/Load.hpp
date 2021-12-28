

#ifndef LoadProcessor_hpp
#define LoadProcessor_hpp

#include "GlobalConfig.hpp"
#include "CountProcessor.hpp"
// #include "FaceDetectProcessor.hpp"
// #include "FaceMaskProcessor.hpp"
// #include "FaceProcessor.hpp"
// #include "DistancingProcessor.hpp"
// #include "FireProcessor.hpp"
// #include "LicenseProcessor.hpp"
// #include "ObjectProcessor.hpp"


class LoadProcessor {
public:
    LoadProcessor();
    ~LoadProcessor();
    void load();
};

#endif