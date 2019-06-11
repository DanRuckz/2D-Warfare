#include "AATurret.h"



AATurret::AATurret() : animation(Vector2i(12, 163), Vector2i(27, 54))
{
	baseptr = this;
	baseptr->setEntity(turretSprite, turretpos, animation, "AA");
	turretSprite.setOrigin(Vector2f(turretSprite.getTextureRect().width / 2, turretSprite.getTextureRect().height / 2));
	turretSprite.setScale(1.5f, 1.5f);
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
