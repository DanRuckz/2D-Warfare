#pragma once
#include "inits.h"
#include "Entities.h"
class MainScreen
{
public:

	Sprite getMainSprite();
	//menu objects needs to be created separately outside of this objects
	MainScreen(sf::RenderWindow* o_window, MainMenuObjects r_objects);
	static int getNumberofPlayers();
	void runMenuWindow();
	bool menuExited();
	bool gameExited();
	~MainScreen();


private:
	Entities* baseptr;
	void PlayMenuMusic();
	sf::RenderWindow* window;
	Vector2f coords;
	VideoMode resolution;
	bool exitedMenu;
	bool exitedGame;
	Vector2i mousePos;
	void fadeColors(Color& color);
	std::string numberOfPlayers;
	void retrieveColors();
	inline void initExitVars();
	inline bool checkExit(Event event);
	MainMenuObjects objects;
	};

