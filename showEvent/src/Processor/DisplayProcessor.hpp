//
//  DisplayProcessor.hpp
//  CamHub
//
//  Created by Pham Quang Hoa on 14/02/2020.
//  Copyright © 2020 Pham Quang Hoa. All rights reserved.
//

#ifndef DisplayProcessor_hpp
#define DisplayProcessor_hpp

#include "Processor.hpp"
// #include "DisplayBoard.hpp"

class DisplayProcessor: public Processor {
public:
    DisplayProcessor(DisplayBoard* displayBoard, int index);
    virtual ~DisplayProcessor();
    virtual void process(Mat& frame);
    
    DisplayBoard* displayBoard;
    int index;
};

#endif /* DisplayProcessor_hpp */
