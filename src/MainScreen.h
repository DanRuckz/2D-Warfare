#pragma once
#include "inits.h"
#include "Entities.h"
class MainScreen : public Entities
{
public:

	Sprite getMainSprite();

	MainScreen();
	MainScreen(RenderWindow* o_window);
	static void setExited(bool other);
	static bool getExited();
	static int getNumberofPlayers();
	~MainScreen();


private:
	Entities* baseptr;
	Sound menuMusic;
	SoundBuffer sb;
	void loadAndPlayMenuSound();
	void createWindow();
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
	static bool exited;
	static int numberofPlayers;
	Vector2i mousePos;
	void fadeColors(Color& color);
	std::string numberOfPlayers;
	void retrieveColors();
};

