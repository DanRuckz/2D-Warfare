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
	void Fly(Sprite& projectile);
	void setFlightDirection(Vector2f vector);
	float getDamage() const;
	~TankShell();

private:
	Sprite shell;
	IntRect animation;
	Projectiles* baseptr;
	Vector2f direction;
	unsigned int turretLength =5;
	float speed;
	float damage = 1000;
};

