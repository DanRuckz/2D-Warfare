#pragma once
#ifndef MAINSCREEN_H
#define MAINSCREEN_H
#include "inits.h"
#include "Entities.h"
#include "MainMenuObjects.h"
#include "globals.h"
#include "Component.h"

class MainScreen : public Component{

public:

	MainScreen(sf::RenderWindow* o_window, Mediator* m);
	Sprite getMainSprite();
	//menu objects needs to be created separately outside of this objects
	void receive(std::string message);
	void runMenuWindow();
	bool menuExited();
	bool gameExited();
	~MainScreen();


private:
	Entities* baseptr;
	void PlayMenuMusic();
	sf::RenderWindow* window;
	Vector2f coords;
	bool exitedMenu;
	bool exitedGame;
	Vector2i mousePos;
	void fadeColors(Color& color);
	std::string numberOfPlayers;
	void retrieveColors();
	inline void initExitVars();
	inline bool checkExit(Event event);
	MainMenuObjects* objects;
	View view;
	inline void resetWindow();
	Mediator* mediator;

	};
#endif
