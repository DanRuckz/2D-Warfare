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
	void reduceDamage(float damage);
	float getHP() const;
	void setPlayer(bool other);
	bool getPlayer() const;
	std::vector<std::shared_ptr<Projectiles>>& getProjectileVector();
	void projectileFly(int index);
	void setRandomPosition();
	void setHP(float Hp);
	int getID();
	void setTarget(Sprite& other);
	Sprite& getTarget();
	float getRadiusofMountPoint();
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
	float HP = 1000;
	bool Player;
	std::vector < std::shared_ptr<Projectiles>> projectiles;
	int ID;
	void setID();
	Sprite target;
	float radiusofMountPoint = 1;
};

