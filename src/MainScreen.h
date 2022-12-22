#pragma once
#include "inits.h"
#include "Entities.h"
class MainScreen : public Entities
{
public:

	Sprite getMainSprite();

	MainScreen(RenderWindow* o_window);
	static int getNumberofPlayers();
	void runMenuWindow();
	bool menuExited();
	bool gameExited();
	~MainScreen();


private:
	Entities* baseptr;
	Sound menuMusic;
	SoundBuffer sb;
	void PlayMenuMusic();
	RenderWindow* window;
	Vector2f coords;
	VideoMode resolution;
	Sprite backgroundSprite;
	Sprite arrowUp;
	Sprite arrowDown;
	Sprite Play;
	Sprite Exit;
	Sprite Players;
	Sprite Rect;
	Font font;
	Text number;
	bool exitedMenu;
	bool exitedGame;
	static int numberofPlayers;
	Vector2i mousePos;
	void fadeColors(Color& color);
	std::string numberOfPlayers;
	void retrieveColors();
	inline void initExitVars();
	inline bool checkExit(Event event);
	};

