#pragma once
#include "Playables.h"
#include "Map.h"
#define OBJ Playables::getObjectsVector()


class AI
{
public:
	AI();
	void AImove();

	void searchMode();

	void attackMode(int i);

	void rotateTurretToEnemy();

	~AI();
private:

	float measureDistance(Sprite & first, Sprite & second);
	void AIrotateToTarget(Sprite& turret, Vector2f enemypos, Vector2f tankpos);
	void AIturretMove(Sprite & entity, Sprite & turret, float radius);
	Clock generalClock;
	Time generalTime;
	float rotateSpeed;
	std::mt19937 gen;
	std::uniform_int_distribution<std::mt19937::result_type> dist;


	//FOR AISEARCH


	bool modeChange = true;
	int random = 0;
	bool timePassed = false;
};

