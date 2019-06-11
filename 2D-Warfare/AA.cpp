#include "AA.h"



AA::AA() :animation(IntRect(Vector2i(7,3),Vector2i(36,79))) ,speed(15),rotateSpeed(5), type("AA")
{
	baseptr = this;
	baseptr->setEntity(anti_air, Vector2f(1500.f, 1500.f), animation, "AA");
	speed = 25;
	aaturret.getTurretSprite().setPosition(anti_air.getPosition().x, anti_air.getPosition().y);
	anti_air.setScale(1.5f, 1.5f);
	baseptr->setHitRadius(projectileMax);
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

void AA::Fire()
{
	Vector2f vector;
	float tempRadius = 14;
	float to_radians = aaturret.getTurretSprite().getRotation() * M_PI / 180;

	if (!left)
	{
		
		shell = std::make_shared <AAShell>();
		
		shell->setRotationOfShot(aaturret.getTurretSprite().getRotation() - 90);
		vector = shell->calculateDirection(shell->getSprite(), barrelLength);
		shell->setPositionOfShot(Vector2f(aaturret.getTurretSprite().getPosition().x + tempRadius * std::cos(to_radians), aaturret.getTurretSprite().getPosition().y + tempRadius * std::sin(to_radians)) + vector);
		vector.x /= barrelLength;
		vector.y /= barrelLength;
		shell->setFlightDirection(vector);
		Projectiles::getProjectileVector().push_back(shell);
	}

	if (left)
	{
		shell = std::make_shared <AAShell>();
		shell->setRotationOfShot(aaturret.getTurretSprite().getRotation() - 90);
		vector = shell->calculateDirection(shell->getSprite(), barrelLength);
		shell->setPositionOfShot(Vector2f(aaturret.getTurretSprite().getPosition().x - tempRadius * std::cos(-to_radians), aaturret.getTurretSprite().getPosition().y + tempRadius * std::sin(-to_radians)) + vector);
		vector.x /= barrelLength;
		vector.y /= barrelLength;
		shell->setFlightDirection(vector);
		Projectiles::getProjectileVector().push_back(shell);
	}
	if (left)
	{
		left = false;
		goto end;
	}
	if (!left)
	{
		left = true;
		goto end;
	}
end: return;
}

Sprite & AA::getShell()
{
	return shell->getSprite();
}


std::shared_ptr<Projectiles> AA::getPointerToProjectile()
{
	return std::shared_ptr<Projectiles>();
}

float AA::getSpeed()
{
	return speed;
}

std::string AA::getType()
{
	return type;
}

void AA::setSelfIndex(int index)
{
	selfIndex = index;
}

int AA::getSelfIndex()
{
	return selfIndex;
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
