#pragma once
#include "Turrets.h"
class Turret : public Turrets
{
public:
	Turret();
	Sprite& getTurretSprite();
	void rotateTurret(Vector2f& mousepos,Vector2f& tankpos);
	//void setTurretPos(Vector2f);
	float getRotateSpeed();
	~Turret();

private:
	Sprite turretSprite;
	float offset_x = 1;
	float offset_y = 13;
	Turrets* baseptr;
	float speed;
	Vector2f turretpos;
	IntRect animation;
	float rotateSpeed;

};

