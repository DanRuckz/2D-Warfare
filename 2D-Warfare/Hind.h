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
	void setSelfIndex(int index);
	int getSelfIndex();
	void setHP(float damage);
	float getHP() const;
	void setPlayer(bool other);
	bool getPlayer() const;
	~Hind();

private:
	float speed;
	float rotateSpeed;
	Playables* baseptr;
	IntRect animation;
	Sprite hind;
	HindBlade hindblade;
	float barrelLength = 40;
	std::shared_ptr<HindShell> shell;
	std::string type;
	float projectileMax;
	int shotsFired = 0;
	int selfIndex;
	float HP = 3000;
	bool Player;
};

