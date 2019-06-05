#pragma once
#include "Entities.h"
class Blades : public Entities
{
public:
	Blades();
	void Spin(Sprite& blade);
	virtual Sprite& getHindSprite() = 0;
	~Blades();

private:

	float rotateSpeed;
};

