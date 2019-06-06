#pragma once
#include "Playables.h"
#include "HindBlade.h"
class Hind :
	public Playables
{
public:
	Hind();
	Sprite& getEntity();
	void moveEntity(std::string);
	void rotateEntity(std::string direction);
	Sprite& getTopPart();
	void Fire();
	Sprite& getShell();
	void projectileFly();
	Projectiles* getPointerToProjectile();
	void rotateTurret();
	~Hind();

private:
	float speed;
	float rotateSpeed;
	Playables* baseptr;
	IntRect animation;
	Sprite hind;
	HindBlade hindblade;
	float offset_x = 2;
	float offset_y = -6;
};

