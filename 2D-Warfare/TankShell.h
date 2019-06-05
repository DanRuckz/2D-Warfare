#pragma once
#include "Projectiles.h"
class TankShell :
	public Projectiles
{
public:
	TankShell();
	void setPositionOfShot(Vector2f position);
	void setRotationOfShot(float angle);
	bool exploded = false;
	Sprite & getSprite();
	void Fly();
	~TankShell();

private:
	Sprite shell;
	IntRect animation;
	Projectiles* baseptr;
	Vector2f direction;
	float turretLength =5;
};

