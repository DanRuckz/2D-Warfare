#pragma once
#include "Entities.h"
#include "Turret.h"
#define ROTATION_ANGLES  global_rotation == 45 || global_rotation == 90 || global_rotation == 135 || global_rotation == 180 ||global_rotation == 225|| global_rotation == 270 || global_rotation == 315 ||global_rotation == 0

//global_rotation == 0 || global_rotation == 18 || global_rotation == 45 || global_rotation == 72 || 
class Tank :
	public Entities
{
public:
	Tank();
	~Tank();
	Sprite& getTopPart();
	void rotateEntity(std::string);
	Turret& getTurret();
	void moveEntity(std::string);
	Sprite& getEntity();
	void rotateTurret(Vector2f,Vector2f);


private:
	Turret turret;
	float offset_x = -1;
	float offset_y = -3;
	Sprite tank;
	IntRect animation;
	float global_rotation = 0;
	float rotateSpeed = 5;
	Entities* baseptr;
	float speed;
	float radius = 1;
};

