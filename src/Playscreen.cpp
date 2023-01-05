#include "Playscreen.h"

Playscreen::Playscreen(){
	resolution = VideoMode::getDesktopMode();
	window.create(resolution, "2D-Warfare", BORDERLESS);
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