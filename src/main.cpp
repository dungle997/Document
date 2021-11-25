#include <iostream>
// #include "AiEngine/InterfaceAi.h"
#include "HttpServer.hpp"

int main()
{
    std::cout << "hello world" << std::endl;
    // sleep(150);
    // InterfaceAi main_program;
    // initAI();
    // while (1)
    // {
    //     processAI(NULL, 12,21);
    //     usleep(500000);
    // }
    HttpServer* server = new HttpServer();
    while (true){
    server->loop();
    }
    delete server;
    // while(1)
    // {
    //     uint32_t status = main_program.processAI();
    //     if (status == -1)
    //         break;
    // }
    return 0;
}
