#include "Playscreen.h"

Playscreen::Playscreen(){
	window.create(resolution, "2D-Warfare", WINDOW_MODE);
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
