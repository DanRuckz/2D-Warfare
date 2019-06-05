#pragma once
#include "inits.h"
#include "Map.h"
#include "Tank.h"
#include "Turret.h"
#include "AA.h"
#include "Hind.h"
#include "Entities.h"

class Window_Manager
{
public:
	Window_Manager();
	~Window_Manager();
private:
	Vector2i mousePos;
	void Window_action();
	void setView();
	RenderWindow window;
	VideoMode resolution;
	Vector2f coords;
	Map map;
	View view;
	Entities * entity;
};

