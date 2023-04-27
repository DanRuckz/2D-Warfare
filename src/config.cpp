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

void Config::setAspectRatio(){
    def_aspect_ratio = DEFAULT_WIDTH/DEFAULT_HEIGHT;
    active_aspect_ratio = this->getResolution().width/this->getResolution().height;
}

sf::Vector2f Config::getScale(){
    if(active_aspect_ratio < def_aspect_ratio){
        return sf::Vector2f({static_cast<float>(DEFAULT_WIDTH)/static_cast<float>(resolution.width), static_cast<float>(DEFAULT_HEIGHT)/static_cast<float>(resolution.height)});
    }
    return sf::Vector2f({static_cast<float>(resolution.width)/static_cast<float>(DEFAULT_WIDTH), static_cast<float>(resolution.height)/static_cast<float>(DEFAULT_HEIGHT)});
}