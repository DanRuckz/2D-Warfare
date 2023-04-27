#include "HindBlade.h"



HindBlade::HindBlade() : animation(Vector2i(706,65),Vector2i(46,56))
{
	baseptr = this;
	blade.setScale(2.5f, 2.5f);
	baseptr->setEntity(blade, Vector2f(0, 0), animation, "hind");
}

Sprite& HindBlade::getBladeSprite()
{
	return blade;
}

void HindBlade::rotateBlade()
{
	baseptr->Spin(blade);
}

HindBlade::~HindBlade()
{
}
