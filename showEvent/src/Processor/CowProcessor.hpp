#ifndef CowProcessor_hpp
#define CowProcessor_hpp
#include <string>
#include <vector>
#include <opencv2/freetype.hpp>

#include "Processor.hpp"
// #include "DisplayBoard.hpp"
// #include "EventManager.hpp"
// #include "GlobalConfig.hpp"

class CowProcessor: public Processor {
public:
    CowProcessor(int cameraId, DisplayBoard* displayBoard, int index, EventManager* eventManager);
    virtual ~CowProcessor();
    virtual void process(Mat& frame);
    
    int cameraId;
    DisplayBoard* displayBoard;
    int index;
    EventManager* eventManager;
};


#endif /* CountProcessor_hpp */
