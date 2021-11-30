#include "FaceRecognize.hpp"

FaceRecognize::FaceRecognize(Processor& p){
    std::cout << "Create Process FaceRecognize" << std::endl;
    this->type   = p.type;
    this->status = p.status;
}
FaceRecognize::~FaceRecognize(){
    std::cout << "Process FaceRecognize Destroyed"<< std::endl;
}
void FaceRecognize::initAI(){
    std::cout << "initialize AI Face Recognize" << std::endl;
    std::cout << "type = " << this->type << std::endl;
    std::cout << "status = " << this->status << std::endl;
}
void FaceRecognize::executeAI(){
    std::cout << "execute AI Face Recognize" << std::endl; 
}