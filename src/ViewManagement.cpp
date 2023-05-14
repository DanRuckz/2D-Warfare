#include "ViewManagement.h"

ViewManagement::ViewManagement(){

	mediator = new WindowMediator();
	auto config = Config::getInstance();
	window.create(config.getResolution(), "2D-Warfare", WINDOW_MODE);
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
