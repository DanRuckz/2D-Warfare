#pragma once
#include "Playables.h"
#include "Map.h"



class AI
{
public:
	AI();
	
	void AImove();

	~AI();


private:

	float measureDistance(Sprite & first, Sprite & second);
	float getAngleBetween(Sprite & first, Sprite & second);
	void AIrotateToTarget(Sprite& entity, Sprite& other,Playables* entityObject, float rotateSpeed);
	void AIrotateAwayFromTarget(Sprite & entity, Sprite & other, Playables * entityObject, float rotateSpeed);
	void AIturretMove(Sprite & entity, Sprite & turret, float radius);
	Clock generalClock;
	Time generalTime;
	float rotateSpeed;
	std::mt19937 gen;
	std::uniform_int_distribution<std::mt19937::result_type> dist;
	float moduluRotation(float rotation);
	bool nearEdge(Playables* object);
	float measureFloats(float first, float second);
	void attackMode();
	void rotateTurretToEnemy();


	//FOR AISEARCH

	bool modeChange = true;
	int random = 0;
	bool timePassed = false;	
	void searchMode();

};

