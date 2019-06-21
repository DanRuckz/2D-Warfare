#pragma once
#include "Projectiles.h"
class Machinegun : public Projectiles
{

public:
	Machinegun();
	void Fly(Sprite& projectile);
	void setPositionOfShot(Vector2f position);
	void setRotationOfShot(float angle);
	Sprite& getSprite();
	void setFlightDirection(Vector2f vector);
	float getDamage() const;
	~Machinegun();
private:
	Projectiles* baseptr;
	Sprite shell;
	float speed;
	Vector2f direction;
	IntRect animation;
	float damage =	50;
};

