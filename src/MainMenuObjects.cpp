#include "MainMenuObjects.h"

MainMenuObjects::MainMenuObjects(){
	resolution = Config::getInstance().getResolution();
	initialize();
}

void MainMenuObjects::initialize(){
	resolution = Config::getInstance().getResolution();
	Vector2i bg_sprite_size = Vector2i(1920,1080);
	arrowUp.setScale(0.3, 0.3);
	arrowDown.setScale(0.3, 0.3);
	Rect.setScale(0.25, 0.25);
    this->setEntity(backgroundSprite, Vector2f(0, 0), IntRect(Vector2i(0, 0), bg_sprite_size), "mainScreen");
	this->setEntity(arrowUp, Vector2f(resolution.width/2, resolution.height/2 -120), IntRect(Vector2i(0, 0), Vector2i(256, 256)), "arrowUp");
	this->setEntity(arrowDown, Vector2f(resolution.width/2, resolution.height/2 + 120), IntRect(Vector2i(0, 0), Vector2i(256, 256)), "arrowDown");
	this->setEntity(Play, Vector2f(resolution.width/2 - 360, resolution.height/2 + 260), IntRect(Vector2i(0, 0), Vector2i(317, 146)), "Play");
	this->setEntity(Exit, Vector2f(resolution.width/2 + 360, resolution.height/2 + 260), IntRect(Vector2i(0, 0), Vector2i(279, 146)), "Exit");
	this->setEntity(Players, Vector2f(resolution.width / 2, resolution.height / 2 - 400), IntRect(Vector2i(0, 0), Vector2i(730, 115)), "players");
	this->setEntity(Rect, Vector2f(resolution.width/2,resolution.height/2), IntRect(Vector2i(0, 0), Vector2i(600, 600)), "rect");
	backgroundSprite.setOrigin(0, 0);
	number.setFont(font);
	number.setCharacterSize(75);
	number.setFillColor(Color::Black);
	number.setString("1");
	numberofPlayers = 1;
	font.loadFromFile("assets/Fonts/ariali.ttf");
	number.setPosition(Vector2f(resolution.width / 2 - 20, resolution.height / 2 - 45));
	if (!sb.loadFromFile("assets/Music/Jesper Kyd - Heroes And Generals German Theme.ogg")) {
		std::cout << "Sound Error";
		return;
	}
}

int MainMenuObjects::getNumberofPlayers(){
	return numberofPlayers;
}

void MainMenuObjects::resetObjects(){
	backgroundSprite.setPosition(Vector2f(0, 0));
	arrowUp.setPosition(Vector2f(resolution.width/2, resolution.height/2 -120));
	arrowDown.setPosition(Vector2f(resolution.width/2, resolution.height/2 + 120));
	Play.setPosition(Vector2f(resolution.width/2 - 360, resolution.height/2 + 260));
	Exit.setPosition(Vector2f(resolution.width/2 + 360, resolution.height/2 + 260));
	Players.setPosition(Vector2f(resolution.width / 2, resolution.height / 2 - 400));
	Rect.setPosition(Vector2f(resolution.width/2,resolution.height/2));
}

MainMenuObjects* MainMenuObjects::getInstance(){
	if(!instance) {
		instance = new MainMenuObjects;
	}
	return instance;
}

