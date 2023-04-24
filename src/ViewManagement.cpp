#include "ViewManagement.h"

ViewManagement::ViewManagement(){

	mediator = new WindowMediator();
	resolution = VideoMode::getDesktopMode();
	window.create(resolution, "2D-Warfare", BORDERLESS);
	Component::initViews();
	viewsMap[Component::Views::MENU] = std::make_unique<MainMenuWindow>(&window, mediator);
	viewsMap[Component::Views::GAME] = std::make_unique<GameWindow>(&window, mediator);
	runGame();
	window.close();
}
    inline void ViewManagement::runGame(){
	while (Component::currentWindow != Component::EXIT){
		viewsMap[Component::currentWindow].get()->runView();
		}
	}

sf::VideoMode ViewManagement::getResolution(){
	return resolution;
}