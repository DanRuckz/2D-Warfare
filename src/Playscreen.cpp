#include "Playscreen.h"

Playscreen::Playscreen(){

	mediator = new WindowMediator();
	resolution = VideoMode::getDesktopMode();
	window.create(resolution, "2D-Warfare", BORDERLESS);
	menuwindow = std::make_unique<MainScreen>(&window, mediator);
	gamewindow = std::make_unique<Window_Manager>(&window, mediator);
	menuwindow->send("Mainscreen is sending...\n");
	gamewindow->send("Window_Manager is sending...\n");
	runGame();
	window.close();
}
    inline void Playscreen::runGame(){
	while (requestedWindow != EXITGAME){
		if(requestedWindow == FIRSTSCREEN){
			menuwindow->runMenuWindow();
		}

		else if (requestedWindow == MENUSCREEN){
			menuwindow->runMenuWindow();
		}	
		
		else if(requestedWindow == GAMESCREEN){
			gamewindow->runGameWindow();
		}
	}
}

sf::VideoMode Playscreen::getResolution(){
	return resolution;
}