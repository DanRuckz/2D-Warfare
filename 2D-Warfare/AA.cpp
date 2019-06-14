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
		projectiles.push_back(shell);
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
		projectiles.push_back(shell);
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

void AA::setHP(float damage)
{
	HP-=damage;
}

float AA::getHP() const
{
	return HP;
}

void AA::setPlayer(bool other)
{
	Player = other;
}

bool AA::getPlayer() const
{
	return Player;
}

std::vector<std::shared_ptr<Projectiles>>& AA::getProjectileVector()
{
	return projectiles;
}

void AA::projectileFly(int index)
{
	for (int i = 0; i < projectiles.size(); i++)
	baseptr->projectileFly(projectiles, projectiles[i], i, index);
}


Sprite& AA::getTopPart()
{
	return aaturret.getTurretSprite();
}
Sprite& AA::getEntity()
{
	return anti_air;
}


void AA::setRandomPosition()
{
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist;
	Vector2f mapSize = Map::getMapSize();
	
				Vector2f temp;
				temp.x = dist(gen) % (int)mapSize.x;
				temp.y = dist(gen) % (int)mapSize.y;
				anti_air.setPosition(temp);
				aaturret.getTurretSprite().setPosition(anti_air.getPosition().x,anti_air.getPosition().y + 15);
			
				startPosition.x = dist(gen) % (int)mapSize.x;
				startPosition.y = dist(gen) % (int)mapSize.y;
}


AA::~AA()
{
}

