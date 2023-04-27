#pragma once
#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H
#include "inits.h"
#include "Entities.h"
#include "MainMenuObjects.h"
#include "globals.h"
#include "Component.h"

class MainMenuWindow : public Component{

public:

	MainMenuWindow(sf::RenderWindow* o_window, Mediator* m);
	Sprite getMainSprite();
	//menu objects needs to be created separately outside of this objects
	void receive(std::string message);
	void runView() override;
	bool menuExited();
	bool gameExited();
	~MainMenuWindow();


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
	sf::VideoMode resolution;
	};
#endif
