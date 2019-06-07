#pragma once
#include "Playables.h"
#include "HindBlade.h"
#include "HindShell.h"
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
	std::shared_ptr<Projectiles> getPointerToProjectile();
	void rotateTurret();
	float getSpeed();
	std::string getType();
	int getShotsFired();
	void nullifyShotsFired();
	~Hind();

private:
	float speed;
	float rotateSpeed;
	Playables* baseptr;
	IntRect animation;
	Sprite hind;
	HindBlade hindblade;
	float barrelLength = 23;
	std::shared_ptr<HindShell> shell;
	std::string type;
	float projectileMax = 1000;
	int shotsFired = 0;
};

