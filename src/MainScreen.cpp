#include "MainScreen.h"


MainScreen::MainScreen(sf::RenderWindow* o_window, Mediator* m) : window(o_window), Component(m), mediator(m) {
	m->add(this);
}

void MainScreen::receive(std::string message){
	std::cout << "Mainscreen Received: " << message << '\n';
}

inline void MainScreen::resetWindow(){
	objects = MainMenuObjects::getInstance();
	objects->resetObjects();
	view.reset(FloatRect(Vector2f(0,0), Vector2f(resolution.width,resolution.height)));
	window->setView(view);

}

Sprite MainScreen::getMainSprite(){
	return objects->backgroundSprite;
}

void MainScreen::PlayMenuMusic() {

	objects->menuMusic.setBuffer(objects->sb);
	objects->menuMusic.setVolume(35);
	objects->menuMusic.play();

}

void MainScreen::runMenuWindow() {
	resetWindow();
	initExitVars();
	Event event;
	Color color;
	color = objects->Play.getColor();
	PlayMenuMusic();
	while (!exitedMenu)
	{
		mousePos = Mouse::getPosition(*window);
		coords = window->mapPixelToCoords(mousePos);
		retrieveColors();
		while (window->pollEvent(event)){
			
			if(event.type == Event::MouseMoved){
				fadeColors(color);
			}
			exitedMenu = checkExit(event);
			if (event.type == Event::MouseButtonPressed){
				if (event.mouseButton.button == Mouse::Left){
					if (objects->Play.getGlobalBounds().contains(coords)){
						exitedMenu = true;
						requestedWindow = GAMESCREEN;
						objects->menuMusic.stop();
						window->clear();
					}
					if (objects->arrowUp.getGlobalBounds().contains(coords)){	
						if (objects->numberofPlayers < 30){
							objects->numberofPlayers += 1;
							numberOfPlayers = std::to_string(objects->numberofPlayers);
							objects->number.setString(numberOfPlayers);
							if (objects->numberofPlayers > 9) objects->number.setPosition(Vector2f(resolution.width / 2 - 45, resolution.height / 2 - 45));
							else objects->number.setPosition(Vector2f(resolution.width / 2 - 20, resolution.height / 2 - 45));
						}
					}
					if (objects->arrowDown.getGlobalBounds().contains(coords)){			
						if (objects->numberofPlayers > 1){
							objects->numberofPlayers -= 1;
							numberOfPlayers = std::to_string(objects->numberofPlayers);
							objects->number.setString(numberOfPlayers);
							if (objects->numberofPlayers > 9) objects->number.setPosition(Vector2f(resolution.width / 2 - 45, resolution.height / 2 - 45));
							else objects->number.setPosition(Vector2f(resolution.width / 2 - 20, resolution.height / 2 - 45));
						}
						
					}
				}
			}
		} //END EVENT
		window->draw(objects->backgroundSprite);
		window->draw(objects->arrowUp);
		window->draw(objects->arrowDown);
		window->draw(objects->Play);
		window->draw(objects->Exit);
		window->draw(objects->Players);
		window->draw(objects->Rect);
		window->draw(objects->number);
		window->display();
	}
}

MainScreen::~MainScreen(){
	
	std::cout << "deconstructing Menu\n";
	mediator->remove(this);
}

inline bool MainScreen::checkExit(Event event){

	if (event.type == Event::Closed){
		objects->menuMusic.stop();
		requestedWindow = EXITGAME;
		return true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape)){
		objects->menuMusic.stop();
		requestedWindow = EXITGAME;
		return true;
	}
	if (objects->Exit.getGlobalBounds().contains(coords) && event.mouseButton.button == Mouse::Left){
		objects->menuMusic.stop();
		requestedWindow = EXITGAME;
		return true;
	}

}

void MainScreen::fadeColors(Color& color){
	if (objects->Play.getGlobalBounds().contains(coords)){
		objects->Play.setColor(Color(color.r, color.g, color.b, 100));
	}
	if (objects->Exit.getGlobalBounds().contains(coords)){
		objects->Exit.setColor(Color(color.r, color.g, color.b, 100));
	}
	if (objects->arrowUp.getGlobalBounds().contains(coords)){
		objects->arrowUp.setColor(Color(color.r, color.g, color.b, 100));
	}
	if (objects->arrowDown.getGlobalBounds().contains(coords)){
		objects->arrowDown.setColor(Color(color.r, color.g, color.b, 100));
	}
}

void MainScreen::retrieveColors(){
		if(!objects->Play.getGlobalBounds().contains(coords))
		objects->Play.setColor(Color(objects->Play.getColor().r, objects->Play.getColor().g, objects->Play.getColor().b,255));
		if (!objects->Exit.getGlobalBounds().contains(coords))
		objects->Exit.setColor(Color(objects->Exit.getColor().r, objects->Exit.getColor().g, objects->Exit.getColor().b, 255));
		if (!objects->arrowUp.getGlobalBounds().contains(coords))
		objects->arrowUp.setColor(Color(objects->arrowUp.getColor().r, objects->arrowUp.getColor().g, objects->arrowUp.getColor().b, 255));
		if (!objects->arrowDown.getGlobalBounds().contains(coords))
		objects->arrowDown.setColor(Color(objects->arrowDown.getColor().r, objects->arrowDown.getColor().g, objects->arrowDown.getColor().b, 255));
}

bool MainScreen::menuExited(){
	return exitedMenu;
}

bool MainScreen::gameExited(){
	return exitedGame;
}

inline void MainScreen::initExitVars(){
	exitedMenu = false;
	exitedGame = false;
}

