#pragma once
#include "inits.h"
#include "Entities.h"
#include "AATurret.h"

class AA : public Entities
{
public:
	AA();
	void moveEntity(std::string);
	void rotateEntity(std::string);
	Sprite & getTopPart();
	Sprite& getEntity();
	void rotateTurret(Vector2f mousepos, Vector2f tankpos);
	~AA();
private:
	Entities* aa;
	IntRect animation;
	Sprite anti_air;
	float speed;
	float rotateSpeed = 5;
	AATurret aaturret;
	float offset_x = 0;
	float offset_y = 23;
	float radiusofMountPoint = 23;
};

