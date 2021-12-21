
#include "GlobalConfig.hpp"

GlobalConfig config;

GlobalConfig::GlobalConfig() {
}
 

GlobalConfig::~GlobalConfig() {
}

void GlobalConfig::load() {
    std::ifstream is("config.json");
    if (is.is_open()) {
        std::string content((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
        try {
            auto j = json::parse(content);
            this->monitors = j["monitors"];
            // this->type = j["type"];
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        
    }
}