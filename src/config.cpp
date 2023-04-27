#include "Config.h"

Config& Config::getInstance() {
    static Config instance;
    return instance;
}

Config::Config(){
    resolution = sf::VideoMode::getDesktopMode();
    if (resolution.isValid()){
        this->setResolution(resolution.width, resolution.height);
    }
    else{
        this->setResolution(m_def_width, m_def_height);
    }
}

void Config::setResolution(uint width, uint height) {
    resolution.width = width;
    resolution.height = height;
}
