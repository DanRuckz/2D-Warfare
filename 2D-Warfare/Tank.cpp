#include "Tank.h"

Tank::Tank() : animation(Vector2i(28,97),Vector2i(34,59)), type("Tank"), rotateSpeed(5)
{
	baseptr = this;
	baseptr->setEntity(tank,Vector2f(1500,1500),animation,"tank");
	speed = 15.f;
	turret.getTurretSprite().setPosition(tank.getPosition().x, tank.getPosition().y);
	tank.setScale(2.5f, 2.5f);
	baseptr->setHitRadius(projectileMax);
	setID();
}

void Tank::Fire()
{
	timeofShot = timerofShot.getElapsedTime();
	if (timeofShot.asSeconds() > 1)
	{

		Vector2f vector;
		shell = std::make_shared <TankShell>();
		shell->setRotationOfShot(turret.getTurretSprite().getRotation() - 90);
		vector = shell->calculateDirection(shell->getSprite(), barrelLength);
		shell->setPositionOfShot(turret.getTurretSprite().getPosition() + vector);
		vector.x /= barrelLength;
		vector.y /= barrelLength;
		shell->setFlightDirection(vector);
		projectiles.push_back(shell);
		timerofShot.restart();
	}

}

Sprite& Tank::getTopPart()
{
	return turret.getTurretSprite();
}

void Tank::moveEntity(std::string direction)
{
	baseptr->moveEntity(tank, direction, tank.getRotation(), speed);
	turret.moveTurret(tank, turret.getTurretSprite(), radius);
}

Sprite& Tank::getEntity()
{
	return tank;
}

void Tank::rotateTurret(Vector2f mousepos, Vector2f tankpos)
{
	turret.rotateTurret(mousepos, tankpos);
	turret.moveTurret(tank, turret.getTurretSprite(), radius);
}

std::string Tank::getType()
{
	return type;
}

void Tank::setSelfIndex(int index)
{
	selfIndex = index;
}

float Tank::getSpeed()
{
	return speed;
}

int Tank::getSelfIndex()
{
	return selfIndex;
}

float Tank::checkIntersectionWithObjects(std::shared_ptr<Projectiles> pointer, int selfObjectIndex)
{
	
		for (int i = 0; i <Playables::getObjectsVector().size(); i++)
		{
			if (pointer->intersectWithObjects(pointer->getSprite(), Playables::getObjectsVector()[i]->getEntity()) && Playables::getObjectsVector()[i]->getType() != "Hind")
			{
				return i;
			}
		}
		return -1;
}

void Tank::reduceDamage(float damage)
{
	HP -= damage;
}

float Tank::getHP() const
{
	return HP;
}

void Tank::setPlayer(bool other)
{
	Player = other;
}

bool Tank::getPlayer() const
{
	return Player;
}

std::vector<std::shared_ptr<Projectiles>>& Tank::getProjectileVector()
{
	return projectiles;

}

void Tank::projectileFly(int index)
{
	for(int i=0;i<projectiles.size();i++)
	baseptr->projectileFly(projectiles,projectiles[i], i, index);
}

void Tank::setRandomPosition()
{
	{
		std::mt19937 gen;
		gen.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> dist;
		Vector2f mapSize = Map::getMapSize();


		Vector2f temp;
		do {
			temp.x = dist(gen) % (int)mapSize.x;
			temp.y = dist(gen) % (int)mapSize.y;
			tank.setPosition(temp);
			turret.getTurretSprite().setPosition(tank.getPosition());
		} while ((temp.x < 30 || temp.x > mapSize.x - 30) && ((temp.y < 30 || temp.y > mapSize.x - 30)));
	}
}

void Tank::setHP(float Hp)
{
	HP = Hp;
}

int Tank::getID()
{
	return ID;
}

void Tank::setTarget(Sprite & other)
{
	target = other;
}

float Tank::getRadiusofMountPoint()
{
	return radiusofMountPoint;
}

float Tank::getRotateSpeed()
{
	return rotateSpeed;
}

Sprite & Tank::getTarget()
{
	return target;
}

int Tank::getRandomMode()
{
	return randomMode;
}

void Tank::setRandomMode(int other)
{
	randomMode = other;
}

void Tank::switchRandomMode(bool other)
{
	switchMode = other;
}

bool Tank::getModeSwitcher()
{
	return switchMode;
}

Turrets * Tank::getTurretPointer()
{
	return &turret;
}

float Tank::getVisibleArea()
{
	return visibleArea;
}

Clock & Tank::getAttackClock()
{
	return attackTimer;
}

Time & Tank::getAttackTime()
{
	return attackTime;
}

int Tank::getKillCount()
{
	return killCount;
}

void Tank::increaseKillCount()
{
	killCount += 1;
}

void Tank::setLastDamaged(int ID)
{
	lastDamaged = ID;
}

int Tank::getLastDamaged()
{
	return lastDamaged;
}

void Tank::rotateEntity(std::string direction)
{
	baseptr->rotateEntity(tank, direction, rotateSpeed);
}

std::shared_ptr<Projectiles> Tank::getPointerToProjectile()
{
	return shell;

}


Sprite& Tank::getShell()
{
	return shell->getSprite();
}


void Tank::setID()
{
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist;

	ID = dist(gen) % INT_MAX;
}


Tank::~Tank()
{
}





