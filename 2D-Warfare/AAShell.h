#pragma once
#include "Projectiles.h"
class AAShell :
	public Projectiles
{
public:
	AAShell();
	void Fly(Sprite& projectile) ;
	void setPositionOfShot(Vector2f position);
	void setRotationOfShot(float angle);
	Sprite& getSprite();
	void setFlightDirection(Vector2f vector);
	~AAShell();
private:
	Projectiles* baseptr;
	Sprite shell;
	float speed;
	Vector2f direction;
	IntRect animation;
	
};

