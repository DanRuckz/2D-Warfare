#pragma once
#include "inits.h"
#include "Map.h"
class Window_Manager
{
public:
	Window_Manager(Map & map);
	//Window_Manager();
	~Window_Manager();
private:
	void makeWindow();
	RenderWindow window;
	VideoMode resolution;
	Vector2f coords;
	Map map;
};

