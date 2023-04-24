#pragma once
#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H
#include "Map.h"
#include "Tank.h"
#include "AA.h"
#include "Hind.h"
#include "TankShell.h"
#include "Entities.h"
#include "RespawnScreen.h"
#include "AI.h"
#include "HighScore.h"
#include "MainMenuObjects.h"
#include "Component.h"


class GameWindow: public Component{
	
	public:
	GameWindow(RenderWindow* o_window, Mediator* m);
	void receive(std::string message);
	void updateHP();
	void runView() override;
	~GameWindow();

private:
	Event event;
	Vector2i mousePos;
	inline void Window_action();
	inline void setView();
	RenderWindow* window;
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
	void vecCheck();
	Clock respawnTimer;
	Time respawnTime;
	HighScore highscore;
	bool rightMouseRelease = true;
	uint numberofplayers = 0;
	void demolishWindowObjects();
	bool windowExited = false;
	inline void setExitedVars();
	Mediator* mediator;
};

#endif