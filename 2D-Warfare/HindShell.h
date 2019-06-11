#pragma once
#include "Projectiles.h"
class HindShell :
	public Projectiles
{
public:
	HindShell();
	void setPositionOfShot(Vector2f position);
	void setRotationOfShot(float angle);
	Sprite & getSprite();
	void Fly(Sprite& projectile);
	void setFlightDirection(Vector2f vector);
	float getDamage() const;
	~HindShell();

private:
	Projectiles* baseptr;
	Sprite shell;
	IntRect animation;
	Vector2f direction;
	float speed;
	float damage = 1000;
};

