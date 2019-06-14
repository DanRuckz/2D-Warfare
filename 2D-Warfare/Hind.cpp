#include "Hind.h"



Hind::Hind() : animation(Vector2i(524, 0), Vector2i(28, 62)), speed(27),rotateSpeed(10),type("Hind"), projectileMax(1700)
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
		float tempRadius = 30;
		float to_radians = hind.getRotation()  * M_PI / 180;;
		shell = std::make_shared <HindShell>();
		shell->setRotationOfShot(hind.getRotation() - 90);
		vector = shell->calculateDirection(shell->getSprite(), barrelLength);
		shell->setPositionOfShot(Vector2f(hind.getPosition().x + tempRadius * std::cos(to_radians),hind.getPosition().y  + tempRadius * std::sin(to_radians)) + vector);
		vector.x /= barrelLength;
		vector.y /= barrelLength;
		shell->setFlightDirection(vector);
		projectiles.push_back(shell);
		

		to_radians = hind.getRotation()  * M_PI / 180;;
		shell = std::make_shared <HindShell>();
		shell->setRotationOfShot(hind.getRotation() - 90);
		vector = shell->calculateDirection(shell->getSprite(), barrelLength);
		shell->setPositionOfShot(Vector2f(hind.getPosition().x - tempRadius * std::cos(-to_radians), hind.getPosition().y + tempRadius * std::sin(-to_radians)) + vector);
		vector.x /= barrelLength;
		vector.y /= barrelLength;
		shell->setFlightDirection(vector);
		projectiles.push_back(shell);
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

void Hind::setSelfIndex(int index)
{
	selfIndex = index;
}

int Hind::getSelfIndex()
{
	return selfIndex;
}

void Hind::setHP(float damage) 
{
	HP -= damage;
}

float Hind::getHP() const
{
	return HP;
}

void Hind::setPlayer(bool other)
{
	Player = other;
}

bool Hind::getPlayer() const
{
	return Player;
}

std::vector<std::shared_ptr<Projectiles>>& Hind::getProjectileVector()
{
	return projectiles;
}

void Hind::projectileFly(int index)
{
	for (int i = 0; i < projectiles.size(); i++)
	baseptr->projectileFly(projectiles, projectiles[i], i, index);
}

Hind::~Hind()
{
}

void Hind::setRandomPosition()
{
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist;
	Vector2f mapSize = Map::getMapSize();
	
				Vector2f temp;
				temp.x = dist(gen) % (int)mapSize.x;
				temp.y = dist(gen) % (int)mapSize.y;
				hind.setPosition(temp);
				hindblade.getBladeSprite().setPosition(hind.getPosition());
	
				startPosition.x = dist(gen) % (int)mapSize.x;
				startPosition.y = dist(gen) % (int)mapSize.y;
}
