#include "Hind.h"



Hind::Hind() : animation(Vector2i(524, 0), Vector2i(28, 62)), speed(20),rotateSpeed(8),type("Hind")
{
	baseptr = this;
	baseptr->setEntity(hind, Vector2f(1500.f, 1500.f), animation, "hind");
	hindblade.getBladeSprite().setPosition(hind.getPosition().x,hind.getPosition().y);
	hind.setScale(2.5f,2.5f);
	baseptr->setHitRadius(projectileMax);
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
		Vector2f vector;
		float offset_x = 25;
		float offset_y = -25;
		shell = std::make_shared <HindShell>();
		shell->setRotationOfShot(hind.getRotation() - 90);
		vector = shell->calculateDirection(shell->getSprite(), barrelLength);
		shell->setPositionOfShot(hind.getPosition());
		vector.x /= barrelLength;
		vector.y /= barrelLength;
		shell->setFlightDirection(vector);
		Projectiles::getProjectileVector().push_back(shell);
		shotsFired += 1;
}

Sprite & Hind::getShell()
{
	// this is false, to change here
	return shell->getSprite();
}


std::shared_ptr<Projectiles> Hind::getPointerToProjectile()
{
	return shell;
}


void Hind::rotateTurret()
{
	hindblade.rotateBlade();
}

float Hind::getSpeed()
{
	return speed;
}

std::string Hind::getType()
{
	return type;
}

int Hind::getShotsFired()
{
	return shotsFired;
}

void Hind::nullifyShotsFired()
{
	shotsFired = 0;
}

Hind::~Hind()
{
}
