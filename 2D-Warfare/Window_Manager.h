#pragma once
#include "inits.h"
#include "Map.h"
#include "Tank.h"
#include "AA.h"
#include "Hind.h"
#include "TankShell.h"
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
	Playables * entity;
	Playables * enemy;
	Projectiles* shot;
	void checkFlight();
	float releaseModeTime = 25;
	float debugModeTime = 1;
};

