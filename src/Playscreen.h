#pragma once
#include "inits.h"
#include "MainScreen.h"
#include "Window_Manager.h"
#include "MainMenuObjects.h"

class Playscreen{
    
public:
Playscreen();
sf::VideoMode getResolution();


private:

	RenderWindow window;
    inline void runGame();
    sf::VideoMode resolution;
    std::unique_ptr<MainMenuObjects> main_menu_objects;
};
