#include "Tank.h"

Tank::Tank() : animation(Vector2i(28,97),Vector2i(34,59)), type("Tank"), speed(20), rotateSpeed(5)
{
	
	target = nullptr;
	baseptr = this;
	baseptr->setEntity(HPText, 50);
	baseptr->setEntity(tank,Vector2f(1500,1500),animation,"tank");
	turret.getTurretSprite().setPosition(tank.getPosition().x, tank.getPosition().y);
	tank.setScale(2.5f, 2.5f);
	setID();
	HPText.setFillColor(Color::Black);
	HPText.setStyle(Text::Bold);
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
		lastFired = "shell";
		timerofShot.restart();

	}

}

Sprite& Tank::getTopPart()
{
	return turret.getTurretSprite();
}

void Tank::moveEntity(std::string direction)
{
	baseptr->moveEntity(tank, direction, speed);
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
	
		for (int i = 0; i <OBJ.size(); i++)
		{
			if (pointer->getType() == "shot" && OBJ[i]->getType() == "Hind" && pointer->intersectWithObjects(pointer->getSprite(), OBJ[i]->getEntity()))
			{
				return i;
			}
			else if (pointer->intersectWithObjects(pointer->getSprite(), OBJ[i]->getEntity()) && OBJ[i]->getType() != "Hind")
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
		} while ((temp.x < 60 || temp.x > mapSize.x - 60) && ((temp.y < 60 || temp.y > mapSize.x - 60)));
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

float Tank::getRadiusofMountPoint()
{
	return radiusofMountPoint;
}

float Tank::getRotateSpeed()
{
	return rotateSpeed;
}

Sprite * Tank::getTarget()
{
	return target;
}

void Tank::setTarget(Sprite * other)
{
	target = other;
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

Text & Tank::getHPText()
{
	return HPText;
}

void Tank::updateHPText()
{
	HPText.setString(std::to_string((int)HP));
	HPText.setPosition(tank.getPosition().x + HPoffset_x, tank.getPosition().y + HPoffset_y);
}

void Tank::setTargetType(std::string type)
{
	targetType = type;
}

std::string Tank::getTargetType()
{
	return targetType;
}

void Tank::fireMachinegun()
{
	timeofMG = timerofMG.getElapsedTime();
	if (timeofMG.asSeconds() > 0.17)
	{
		
		Vector2f vector;
		shell = std::make_shared <Machinegun>();
		shell->setRotationOfShot(turret.getTurretSprite().getRotation() - 90);
		vector = shell->calculateDirection(shell->getSprite(), barrelLength);
		shell->setPositionOfShot(turret.getTurretSprite().getPosition() + vector);
		vector.x /= barrelLength;
		vector.y /= barrelLength;
		shell->setFlightDirection(vector);
		projectiles.push_back(shell);
		lastFired = "shot";
		timerofMG.restart();
	}
}

bool Tank::getNearEdge()
{
	return nearEdge;
}

void Tank::setNearEdge(bool option)
{
	nearEdge = option;
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





