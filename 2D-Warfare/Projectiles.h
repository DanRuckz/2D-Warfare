#pragma once
#include "Entities.h"
class Projectiles : public Entities
{
public:
	Projectiles();
	virtual void Fly() = 0;
	virtual Vector2f calculateDirection(Sprite& shell,float barrelLength);
	virtual void setPositionOfShot(Vector2f position) = 0;
	virtual void setRotationOfShot(float angle) = 0;
	virtual Sprite & getSprite() =0;
	virtual void Fly(Sprite& projectile, float speed, Vector2f direction);
	float getDistanceTraveled();
	virtual ~Projectiles();

private:

	float m_distanceTraveled = 0;
	Vector2f distanceVector;
	void distanceTraveled(float speed, Vector2f direction);

protected:
};

