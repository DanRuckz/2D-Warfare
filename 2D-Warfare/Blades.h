#pragma once
#include "Entities.h"
class Blades : public Entities
{
public:
	Blades();
	void Spin(Sprite& blade);
	~Blades();

private:

	float rotateSpeed;
};

