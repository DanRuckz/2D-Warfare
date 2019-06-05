#pragma once
#include "Entities.h"
class Turrets :
	public Entities
{
public:
	Turrets();
	virtual void rotateTurret(Sprite& turret ,Vector2f mousepos, Vector2f tankpos);
	virtual void moveTurret(Sprite& entity, Sprite& turret, float radius);
	virtual Sprite& getTurretSprite() = 0;
	~Turrets();
};

