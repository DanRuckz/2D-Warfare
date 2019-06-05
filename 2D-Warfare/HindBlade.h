#pragma once
#include "Blades.h"
class HindBlade :
	public Blades
{
public:
	HindBlade();
	Sprite & getHindSprite();
	void rotateBlade();
	~HindBlade();

private:
	Blades* baseptr;
	Sprite blade;
	IntRect animation;
};

