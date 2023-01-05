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
#include "MainMenuObjects.h"
#include "globals.h"
class Window_Manager{
	
	public:
	Window_Manager(RenderWindow* o_window);
	void updateHP();
	void runGameWindow();
	~Window_Manager();

private:
	std::shared_ptr<Window_Manager> baseptr;
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
};

