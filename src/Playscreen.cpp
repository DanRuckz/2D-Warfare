#include "Playscreen.h"

Playscreen::Playscreen(){
	resolution = sf::VideoMode(1920,1080);
	window.create(resolution, "2D-Warfare", 0);
	runGame();
	window.close();
}

    inline void Playscreen::runGame(){
	while (requestedWindow != EXITGAME){
		if(requestedWindow == FIRSTSCREEN){
			auto menuwindow = std::make_unique<MainScreen>(&window);
		}
		else if (requestedWindow == MENUSCREEN){
			auto menuwindow = std::make_unique<MainScreen>(&window);
		}
		
		else if(requestedWindow == GAMESCREEN){
			auto gamewindow = std::make_unique<Window_Manager>(&window);
		}
	}
}

sf::VideoMode Playscreen::getResolution(){
	return resolution;
}