#pragma once
#include "Entities.h"
#include "HindBlade.h"
class Hind :
	public Entities
{
public:
	Hind();
	Sprite& getEntity();
	void moveEntity(std::string);
	void rotateEntity(std::string direction);
	Sprite& getTopPart();
	~Hind();

private:
	float speed;
	float rotateSpeed;
	Entities* baseptr;
	IntRect animation;
	Sprite hind;
	HindBlade hindblade;
	float offset_x = 2;
	float offset_y = -6;
};

