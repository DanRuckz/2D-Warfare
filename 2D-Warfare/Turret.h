#pragma once
#include "Entities.h"
class Turret : public Entities
{
public:
	Turret();
	Sprite& getTurretSprite();
	void rotateTurret(Vector2f,Vector2f);
	void setTankPos(Vector2f);
	~Turret();

private:
	Sprite turretSprite;
	float offset_x = 1;
	float offset_y = 13;
	Entities* baseptr;
	float speed;
	Vector2f tankpos;
	IntRect animation;
};

