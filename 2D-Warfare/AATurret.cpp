#include "AATurret.h"



AATurret::AATurret() : animation(Vector2i(11, 161), Vector2i(29, 56))
{
	baseptr = this;
	baseptr->setEntity(turretSprite, turretpos, animation, "AA");
	turretSprite.setOrigin(Vector2f(turretSprite.getTextureRect().width / 2 + offset_x, turretSprite.getTextureRect().height / 2 + offset_y));
	
}

Sprite & AATurret::getTurretSprite()
{
	return turretSprite;
}

void AATurret::rotateTurret(Vector2f& mousepos, Vector2f& tankpos)
{
	baseptr->rotateTurret(turretSprite, mousepos, tankpos);
}



AATurret::~AATurret()
{
}
