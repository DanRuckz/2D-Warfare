#include "Hind.h"



Hind::Hind() : animation(Vector2i(524, 0), Vector2i(28, 62)), speed(33),rotateSpeed(10),type("Hind")
{
	target = nullptr;
	baseptr = this;
	baseptr->setEntity(HPText, 50);
	baseptr->setEntity(hind, Vector2f(1500.f, 1500.f), animation, "hind");
	hindblade.getBladeSprite().setPosition(hind.getPosition().x,hind.getPosition().y);
	hind.setScale(2.5f,2.5f);
	setID();
	HPText.setFillColor(Color::Black);
	HPText.setStyle(Text::Bold);
}

Sprite & Hind::getEntity()
{
	return hind;
}

void Hind::moveEntity(std::string direction)
{
	baseptr->moveEntity(hind, direction, speed);
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
	timeBetweenShots = timerBetweenShots.getElapsedTime();
	timeofShot = timerofShot.getElapsedTime();
	if (shotsFired < 5 && timeBetweenShots.asSeconds() > 0.15)
	{
		Vector2f vector;
		float tempRadius = 30;
		float to_radians = hind.getRotation()  * M_PI / 180;;
		shell = std::make_shared <HindShell>();
		shell->setRotationOfShot(hind.getRotation() - 90);
		vector = shell->calculateDirection(shell->getSprite(), barrelLength);
		shell->setPositionOfShot(Vector2f(hind.getPosition().x + tempRadius * std::cos(to_radians), hind.getPosition().y + tempRadius * std::sin(to_radians)) + vector);
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
		timerBetweenShots.restart();
	}
	if (shotsFired == 4)
	{
		timerofShot.restart();
	}
	timeofShot = timerofShot.getElapsedTime();
	if (shotsFired >= 5 && timeofShot.asSeconds() <= 4)
	{
		reloading = true;
	}
	if (shotsFired >= 5 && timeofShot.asSeconds() > 4)
	{
		nullifyShotsFired();
		reloading = false;
	}
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

void Hind::reduceDamage(float damage) 
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
		do{
		temp.x = dist(gen) % (int)mapSize.x;
		temp.y = dist(gen) % (int)mapSize.y;
		hind.setPosition(temp);
		hindblade.getBladeSprite().setPosition(hind.getPosition());
	}
		while ((temp.x < 60 || temp.x > mapSize.x - 60) && ((temp.y < 60 || temp.y > mapSize.x - 60)));
}
void Hind::setHP(float Hp)
{
	HP = Hp;
}


int Hind::getID()
{
	return ID;
}

void Hind::setTarget(Sprite *other)
{

	target = other;
}

Sprite * Hind::getTarget()
{
	return target;
}


float Hind::getRotateSpeed()
{
	return rotateSpeed;
}

float Hind::getRadiusofMountPoint()
{
	return radiusofMountPoint;
}

int Hind::getRandomMode()
{
	return randomMode;
}

void Hind::setRandomMode(int other)
{
	randomMode = other;
}

void Hind::switchRandomMode(bool other)
{
	switchMode = other;
}

bool Hind::getModeSwitcher()
{
	return switchMode;
}

float Hind::getVisibleArea()
{
	return visibleArea;
}

Clock & Hind::getAttackClock()
{
	return attackTimer;

}

Time & Hind::getAttackTime()
{
	return attackTime;

}

int Hind::getKillCount()
{
	return killCount;
}

void Hind::increaseKillCount()
{
	killCount += 1;
}

void Hind::setLastDamaged(int ID)
{
	lastDamaged = ID;
}

int Hind::getLastDamaged()
{
	return lastDamaged;
}

Text & Hind::getHPText()
{
	return HPText;
}

void Hind::setID()
{
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist;

	ID = dist(gen) % INT_MAX;
}

void Hind::updateHPText()
{
	HPText.setString(std::to_string((int)HP));
	HPText.setPosition(hind.getPosition().x + HPoffset_x, hind.getPosition().y + HPoffset_y);
}

void Hind::setTargetType(std::string type)
{
	targetType = type;
}

std::string Hind::getTargetType()
{
	return targetType;
}

bool Hind::getReloading()
{
	return reloading;
}

bool Hind::getNearEdge()
{
	return nearEdge;
}

void Hind::setNearEdge(bool option)
{
	nearEdge = option;
}

