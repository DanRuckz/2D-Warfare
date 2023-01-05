#include "HindBlade.h"



HindBlade::HindBlade() : animation(Vector2i(706,65),Vector2i(46,56))
{
	baseptr = this;
	baseptr->setEntity(blade, Vector2f(0, 0), animation, "hind");
	blade.setScale(2.5f, 2.5f);
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
