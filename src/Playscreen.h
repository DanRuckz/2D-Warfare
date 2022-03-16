#pragma once
#include "inits.h"
#include "MainScreen.h"
#include "Window_Manager.h"

class Playscreen{
    
public:
Playscreen();


private:

	RenderWindow window;
	VideoMode resolution;
    inline void createwindow();
};