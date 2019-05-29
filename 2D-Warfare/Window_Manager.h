#pragma once
#include "inits.h"
class Window_Manager
{
public:
	Window_Manager();
	~Window_Manager();
private:
	void makeWindow();
	RenderWindow window;
	VideoMode resolution;
	Vector2f coords;
};

