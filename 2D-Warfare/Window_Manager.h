#pragma once
#include "inits.h"
#include "Map.h"
#include "Tank.h"
#include "AA.h"
#include "Hind.h"
#include "TankShell.h"
#include "Entities.h"
#include "RespawnScreen.h"

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
	Playables* entity;
	Playables* enemy;
	Projectiles* shot;
	void checkFlight();
	void checkHP();
	void limitEntity(std::string direction);
	void checkLimits();
	float releaseModeTime = 32;
	float debugModeTime = 1;
	float factor = 1.5;
	void makeEntity();
	void makeEnemies(int howmany);
	void drawRespawn();
	void correctDraw(std::string type);
	bool mouseRelease = true;
	std::unique_ptr<RespawnScreen> respawnScreen;
};

