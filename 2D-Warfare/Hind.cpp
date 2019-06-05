#include "Hind.h"



Hind::Hind() : animation(Vector2i(524, 0), Vector2i(28, 62)), speed(20),rotateSpeed(8)
{
	baseptr = this;
	baseptr->setEntity(hind, Vector2f(1000.f, 1000.f), animation, "hind");
	hindblade.getHindSprite().setPosition(hind.getPosition().x,hind.getPosition().y);
}

Sprite & Hind::getEntity()
{
	return hind;
}

void Hind::moveEntity(std::string direction)
{
	baseptr->moveEntity(hind, direction, hind.getRotation(), speed);
	hindblade.getHindSprite().setPosition(hind.getPosition().x,hind.getPosition().y);
	hindblade.rotateBlade();
}

void Hind::rotateEntity(std::string direction)
{
	baseptr->rotateEntity(hind, direction, rotateSpeed);
	//aaturret.moveTurret(anti_air, aaturret.getTurretSprite(), radiusofMountPoint);


}

Sprite & Hind::getTopPart()
{
	return hindblade.getHindSprite();
}

Hind::~Hind()
{
}
