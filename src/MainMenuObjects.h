#include "inits.h"
#include "Entities.h"
#include "MainMenuWindow.h"

#ifndef MAINMENUOBJECTS_H
#define MAINMENUOBJECTS_H

class MainMenuObjects : public Entities
{
public:

	static MainMenuObjects* getInstance();
	void initialize();
	Sound menuMusic;
	Sprite backgroundSprite;
	Sprite arrowUp;
	Sprite arrowDown;
	Sprite Play;
	Sprite Exit;
	Sprite Players;
	Sprite Rect;
	Font font;
	Text number;
	SoundBuffer sb;
	static int getNumberofPlayers();
	static int numberofPlayers;
	void resetObjects();

private:
	static MainMenuObjects* instance;
	MainMenuObjects();
	};

#endif