#include "AA.h"



AA::AA() :animation(IntRect(Vector2i(7,3),Vector2i(36,79))) ,speed(10), type("AA"), rotateSpeed(7)
{
	baseptr = this;
	baseptr->setEntity(HPText, 50);
	baseptr->setEntity(anti_air, Vector2f(1500.f, 1500.f), animation, "AA");
	speed = 25;
	aaturret.getTurretSprite().setPosition(anti_air.getPosition().x, anti_air.getPosition().y);
	anti_air.setScale(1.5f, 1.5f);
	setID();
	HPText.setFillColor(Color::Black);
	HPText.setStyle(Text::Bold);
}

void AA::moveEntity(std::string direction)
{
	baseptr->moveEntity(anti_air, direction, speed);
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
	timeofShot = timerofShot.getElapsedTime();
	if (timeofShot.asSeconds() > 0.25)
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
			timerofShot.restart();
			return;
		}
		if (!left)
		{
			left = true;
			timerofShot.restart();
			return;
		}
		
	}
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

void AA::reduceDamage(float damage)
{
	HP-=damage;
}

void AA::setHP(float Hp)
{
	HP = Hp;
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
				do {
					temp.x = dist(gen) % (int)mapSize.x;
					temp.y = dist(gen) % (int)mapSize.y;
					anti_air.setPosition(temp);
					aaturret.getTurretSprite().setPosition(anti_air.getPosition().x, anti_air.getPosition().y + 23);
				} while ((temp.x < 60 || temp.x > mapSize.x - 60) && ((temp.y < 60 || temp.y > mapSize.x - 60)));
			
}

void AA::setTarget(Sprite * other)
{
	target = other;
}

int AA::getID()
{
	return ID;
}

Sprite * AA::getTarget()
{
	return target;
}

float AA::getRadiusofMountPoint()
{
	return radiusofMountPoint;
}

float AA::getRotateSpeed()
{
	return rotateSpeed;
}

int AA::getRandomMode()
{
	return randomMode;
}

void AA::setRandomMode(int other)
{
	randomMode = other;
}

void AA::switchRandomMode(bool other)
{
	switchMode = other;
}

bool AA::getModeSwitcher()
{
	return switchMode;
}

Turrets * AA::getTurretPointer()
{
	return &aaturret;
}

float AA::getVisibleArea()
{
	return visibleArea;
}

Clock & AA::getAttackClock()
{
	return attackTimer;

}

Time & AA::getAttackTime()
{
	return attackTime;
}

int AA::getKillCount()
{
	return killCount;
}

void AA::increaseKillCount()
{
	killCount += 1;
}

void AA::setLastDamaged(int ID)
{
	lastDamaged = ID;
}

int AA::getLastDamaged()
{
	return lastDamaged;
}

Text & AA::getHPText()
{
	return HPText;
}

void AA::updateHPText()
{
	HPText.setString(std::to_string((int)HP));
	HPText.setPosition(anti_air.getPosition().x + HPoffset_x, anti_air.getPosition().y + HPoffset_y);
}

void AA::setTargetType(std::string type)
{
	targetType = type;
}

std::string AA::getTargetType()
{
	return targetType;
}

bool AA::getNearEdge()
{
	return nearEdge;
}

void AA::setNearEdge(bool option)
{
	nearEdge = option;
}



void AA::setID()
{
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist;

	ID = dist(gen) % INT_MAX;
}



AA::~AA()
{
}

