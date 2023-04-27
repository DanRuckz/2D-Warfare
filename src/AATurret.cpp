#include "AATurret.h"



AATurret::AATurret() : animation(Vector2i(12, 163), Vector2i(27, 54)), rotateSpeed(5)
{
	baseptr = this;
	turretSprite.setScale(1.5f, 1.5f);
	baseptr->setEntity(turretSprite, turretpos, animation, "AA");
	turretSprite.setOrigin(Vector2f(turretSprite.getTextureRect().width / 2, turretSprite.getTextureRect().height / 2));
}

Sprite & AATurret::getTurretSprite()
{
	return turretSprite;
}

void AATurret::rotateTurret(Vector2f& mousepos, Vector2f& tankpos)
{
	baseptr->rotateTurret(turretSprite, mousepos, tankpos);
}



float AATurret::getRotateSpeed()
{
	return rotateSpeed;
}


AATurret::~AATurret()
{
}
