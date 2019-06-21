#pragma once
#include "inits.h"
#include "Map.h"
#include "Tank.h"
#include "AA.h"
#include "Hind.h"
#include "TankShell.h"
#include "Entities.h"
#include "RespawnScreen.h"
#include "AI.h"
#include "HighScore.h"

class Window_Manager
{
public:
	Window_Manager();
	void updateHP();
	~Window_Manager();
private:
	Event event;
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
	float releaseModeTime = 40;
	float debugModeTime = 1;
	float factor = 1.5;
	void makeEntity(std::string type);
	void makeEnemies(int howmany);
	void drawRespawn();
	void correctDraw();
	void movement();
	void drawProjectiles();
	void respawn();
	void checkCollisionWithObjects();
	bool mouseRelease = true;
	std::unique_ptr<RespawnScreen> respawnScreen;
	Vector2f RespawnScreenStartPos;
	std::string type;
	AI ai;
	int numOfEnemies = 20;
	void vecCheck();
	Clock respawnTimer;
	Time respawnTime;
	HighScore highscore;
	bool rightMouseRelease = true;
};

