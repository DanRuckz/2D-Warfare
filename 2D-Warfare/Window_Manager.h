#pragma once
#include "inits.h"
#include "Map.h"
class Window_Manager
{
public:
	Window_Manager();
	~Window_Manager();
private:
	void Window_action();
	void setView();
	RenderWindow window;
	VideoMode resolution;
	Vector2f coords;
	Map map;
	View view;
};

