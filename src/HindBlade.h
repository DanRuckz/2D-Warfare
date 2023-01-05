#pragma once
#include "Blades.h"
class HindBlade :
	public Blades
{
public:
	HindBlade();
	Sprite & getBladeSprite();
	void rotateBlade();
	~HindBlade();

private:
	Blades* baseptr;
	Sprite blade;
	IntRect animation;
};

