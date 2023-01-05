#pragma once
#include "inits.h"
#include "Entities.h"
#include "MainMenuObjects.h"
#include "globals.h"

class MainScreen{

public:

	Sprite getMainSprite();
	//menu objects needs to be created separately outside of this objects
	MainScreen(sf::RenderWindow* o_window);
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

	};

