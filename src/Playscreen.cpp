#include "Playscreen.h"

Playscreen::Playscreen(){
	resolution = VideoMode::getDesktopMode();
	main_menu_objects = std::make_unique<MainMenuObjects>();
	std::cout << resolution.width << "X" << resolution.height << '\n';
	window.create(resolution, "2D-Warfare", WINDOW_MODE);
	runGame();
	window.close();
}

    inline void Playscreen::runGame(){
	while (requestedWindow != EXITGAME){
		if(requestedWindow == FIRSTSCREEN){
			auto menuwindow = std::make_unique<MainScreen>(&window, main_menu_objects);
		}
		else if (requestedWindow == MENUSCREEN){
			auto menuwindow = std::make_unique<MainScreen>(&window, main_menu_objects);
		}
		
		else if(requestedWindow == GAMESCREEN){
			auto gamewindow = std::make_unique<Window_Manager>(&window);
		}
	}
}

sf::VideoMode Playscreen::getResolution(){
	return resolution;
}