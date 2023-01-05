#pragma once
#include "inits.h"
#include "globals.h"
#include "MainScreen.h"
#include "Window_Manager.h"
#ifndef PLAYSCREEN
#define PLAYSCREEN
class Playscreen{
    
public:
Playscreen();
sf::VideoMode getResolution();


private:

	RenderWindow window;
    inline void runGame();
    sf::VideoMode resolution;
};

#endif