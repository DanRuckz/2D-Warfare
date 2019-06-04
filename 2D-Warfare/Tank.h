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
	Sprite& getTank();
	Sprite& getTurretSprite();
	void rotateEntity(std::string);
	Turret& getTurret();
	void moveEntity(std::string);


private:
	Turret turret;
	//void saveTextures();
	float offset_x = -1;
	float offset_y = -3;
	Sprite tank;
	IntRect animation;
	float global_rotation = 0;
	float rotateSpeed = 5;
	//void checkRotation();
	//int determineType(float);
	Entities* baseptr;
	float speed;
};

