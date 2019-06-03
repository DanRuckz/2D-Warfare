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
	void moveTank(std::string);
	void rotateTank(std::string);
	Texture & getCurrentTexture();
	Turret& getTurret();


private:
	void makeEntity();
	Turret turret;
	void saveTextures();
	void setEntity();
	float speed;
	float offset_x = -1;
	float offset_y = -3;
	Texture texture;
	void changeAnimation(float angle);
	Sprite tank;
	std::vector<IntRect> animation;
	float rotation_p = 0;
	float global_rotation = 0;
	float rotateSpeed = 1;
	void checkRotation();

};

