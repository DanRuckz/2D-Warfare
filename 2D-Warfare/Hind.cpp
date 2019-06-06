#include "Hind.h"



Hind::Hind() : animation(Vector2i(524, 0), Vector2i(28, 62)), speed(20),rotateSpeed(8)
{
	baseptr = this;
	baseptr->setEntity(hind, Vector2f(1500.f, 1500.f), animation, "hind");
	hindblade.getBladeSprite().setPosition(hind.getPosition().x,hind.getPosition().y);
	hind.setScale(2.5f,2.5f);
}

Sprite & Hind::getEntity()
{
	return hind;
}

void Hind::moveEntity(std::string direction)
{
	baseptr->moveEntity(hind, direction, hind.getRotation(), speed);
	hindblade.getBladeSprite().setPosition(hind.getPosition().x,hind.getPosition().y);
}

void Hind::rotateEntity(std::string direction)
{
	baseptr->rotateEntity(hind, direction, rotateSpeed);
}



Sprite & Hind::getTopPart()
{
	return hindblade.getBladeSprite();
}

void Hind::Fire()
{
}

Sprite & Hind::getShell()
{
	// this is false, to change here
	return hind;
}

void Hind::projectileFly()
{
}

Projectiles * Hind::getPointerToProjectile()
{
	//to be changed
	return nullptr;
}

void Hind::rotateTurret()
{
	hindblade.rotateBlade();
}

Hind::~Hind()
{
}
