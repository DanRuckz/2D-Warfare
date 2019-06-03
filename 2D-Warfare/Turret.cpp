#include "Turret.h"

Turret::Turret() : animation(Vector2i(30,276),Vector2i(31,60))
{
	baseptr = this;
	baseptr->setEntity(turretSprite,tankpos, animation);
	turretSprite.setOrigin(Vector2f(turretSprite.getTextureRect().width / 2 + offset_x, turretSprite.getTextureRect().height / 2 + offset_y));
}


Sprite& Turret::getTurretSprite()
{
	return turretSprite;
}


void Turret::rotateTurret(Vector2f mousepos, Vector2f tankpos)
{
	baseptr->rotateTurret(turretSprite, mousepos, tankpos);
}

void Turret::setTankPos(Vector2f tankposi)
{
	tankpos = tankposi;
}

	

Turret::~Turret()
{
}
