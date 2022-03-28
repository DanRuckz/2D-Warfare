#include "Playscreen.h"



Playscreen::Playscreen(){
createwindow();
}

    inline void Playscreen::createwindow(){
	resolution = VideoMode::getDesktopMode();
	//resolution.width = 1920;
	//resolution.height = 1080;
	window.create(resolution, "2D-Warfare", WINDOW_MODE);

	auto menuwindow = std::make_unique<MainScreen>(&window);
	auto gamewindow = std::make_unique<Window_Manager>(&window);

	while(true){
		menuwindow->runMenuWindow();
		if(menuwindow->gameExited()) {
			break;
		}
		gamewindow->runGameWindow();
	}
	window.close();
}
