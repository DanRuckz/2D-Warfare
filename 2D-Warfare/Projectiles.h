#pragma once
#include "Entities.h"
#include "Collision.h"
#include "Map.h"
class Projectiles : public Entities
{
public:
	Projectiles();
	virtual Vector2f calculateDirection(Sprite& shell,float barrelLength);
	virtual void Fly(Sprite& projectile) = 0;
	virtual void setPositionOfShot(Vector2f position) = 0;
	virtual void setRotationOfShot(float angle) = 0;
	virtual Sprite& getSprite() =0;
	virtual void setFlightDirection(Vector2f vector) = 0;
	virtual void Fly(Sprite& projectile, float speed, Vector2f direction);
	float getDistanceTraveled();
	bool intersectWithMap(Sprite& shell);
	bool intersectWithObjects(Sprite& shell, Sprite& object);
	static std::vector<std::shared_ptr<Projectiles>>& getProjectileVector();
	virtual ~Projectiles();

private:
	float m_distanceTraveled = 0;
	Vector2f distanceVector;
	void distanceTraveled(float speed, Vector2f direction);
	static std::vector<std::shared_ptr<Projectiles>> projectilesVector;
};

