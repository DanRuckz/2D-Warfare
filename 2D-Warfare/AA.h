#pragma once
#include "Playables.h"
#include "AATurret.h"
#include "AAShell.h"

class AA : public Playables
{
public:
	AA();
	void moveEntity(std::string);
	void rotateEntity(std::string);
	Sprite & getTopPart();
	Sprite& getEntity();
	void rotateTurret(Vector2f mousepos, Vector2f tankpos);
	void Fire();
	Sprite& getShell();
	std::shared_ptr<Projectiles> getPointerToProjectile();
	float getSpeed();
	std::string getType();
	void setSelfIndex(int index);
	int getSelfIndex();
	~AA();
private:
	Playables* baseptr;
	IntRect animation;
	Sprite anti_air;
	float speed;
	float rotateSpeed = 5;
	AATurret aaturret;
	float offset_x = 0;
	float offset_y = 23;
	float radiusofMountPoint = 23;
	std::string type;
	float projectileMax = 1000;
	std::shared_ptr<AAShell> shell;
	float barrelLength = 23;
	bool left = false;
	int selfIndex;
};

