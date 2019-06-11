#include "Turret.h"

Turret::Turret() : animation(Vector2i(31,276),Vector2i(28,59))
{
	baseptr = this;
	baseptr->setEntity(turretSprite,turretpos, animation,"tank_turret");
	turretSprite.setOrigin(Vector2f(turretSprite.getTextureRect().width / 2 + offset_x, turretSprite.getTextureRect().height / 2 + offset_y));
	turretSprite.setScale(2.4f, 2.4f);
}


Sprite& Turret::getTurretSprite()
{
	return turretSprite;
}



void Turret::rotateTurret(Vector2f& mousepos, Vector2f& tankpos)
{
	baseptr->rotateTurret(turretSprite, mousepos, tankpos);
}

Turret::~Turret()
{
}
