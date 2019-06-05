#include "AA.h"



AA::AA() :animation(IntRect(Vector2i(6,2),Vector2i(38,82))) ,speed(15),rotateSpeed(5)
{
	baseptr = this;
	baseptr->setEntity(anti_air, Vector2f(1000.f, 1000.f), animation, "AA");
	speed = 25;
	aaturret.getTurretSprite().setPosition(anti_air.getPosition().x +offset_x, anti_air.getPosition().y+ offset_y);
}

void AA::moveEntity(std::string direction)
{
	baseptr->moveEntity(anti_air, direction, anti_air.getRotation(), speed);
	aaturret.moveTurret(anti_air, aaturret.getTurretSprite(), radiusofMountPoint);
}

void AA::rotateEntity(std::string direction)
{
	baseptr->rotateEntity(anti_air, direction, rotateSpeed);
	aaturret.moveTurret(anti_air,aaturret.getTurretSprite(),radiusofMountPoint);


}

void AA::rotateTurret(Vector2f mousepos, Vector2f tankpos)
{
	aaturret.rotateTurret(mousepos, tankpos);
}

Sprite& AA::getTopPart()
{
	return aaturret.getTurretSprite();
}
Sprite& AA::getEntity()
{
	return anti_air;
}

AA::~AA()
{
}
