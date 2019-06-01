#pragma once
#include "inits.h"
class MenuScreen
{
public:
	MenuScreen();
	~MenuScreen();
private:

	void createWindow();
	RenderWindow window;
	VideoMode resolution;
	Vector2f coords;
	void createBackground();

	void loadAndPlayMenuSound();

	Texture texture;
	Sprite background;
	Sound menuMusic;
	SoundBuffer sb;

};

