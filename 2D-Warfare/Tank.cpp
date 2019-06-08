#include "Tank.h"

Tank::Tank() : animation(Vector2i(28,97),Vector2i(34,59)), type("Tank")
{
	baseptr = this;
	baseptr->setEntity(tank,Vector2f(1500,1500),animation,"tank");
	speed = 15.f;
	turret.getTurretSprite().setPosition(tank.getPosition().x, tank.getPosition().y);
	tank.setScale(2.5f, 2.5f);
	baseptr->setHitRadius(projectileMax);
}

void Tank::Fire()
{
		Vector2f vector;
		shell = std::make_shared <TankShell>();
		shell->setRotationOfShot(turret.getTurretSprite().getRotation() - 90);
		vector = shell->calculateDirection(shell->getSprite(), barrelLength);
		shell->setPositionOfShot(turret.getTurretSprite().getPosition() + vector);
		vector.x /= barrelLength;
		vector.y /= barrelLength;
		shell->setFlightDirection(vector);
		Projectiles::getProjectileVector().push_back(shell);
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

bool Tank::checkIntersectionWithObjects(std::shared_ptr<Projectiles> pointer, int selfObjectIndex)
{
	
		bool intersection = false;
		for (int i = 0; i <Playables::getObjectsVector().size(); i++)
		{
			if (pointer->intersectWithObjects(pointer->getSprite(), Playables::getObjectsVector()[i]->getEntity()) && Playables::getObjectsVector()[i]->getType() != "Hind")
			{
				intersection = true;
				return intersection;
			}
		}
		return intersection;
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

Tank::~Tank()
{
}







/*
ANIMATIONS I MIGHT USE.

void Tank::saveTextures()
{
	IntRect temp;
	temp.left = 27;
	temp.top = 96;
	temp.width = 41;
	temp.height = 62;
	animation.push_back(temp);


	temp.left = 205;
	temp.top = 94;
	temp.width = 63;
	temp.height = 65;
	animation.push_back(temp);


	temp.left = 397;
	temp.top = 107;
	temp.width = 64;
	temp.height = 41;
	animation.push_back(temp);

	temp.left = 592;
	temp.top = 97;
	temp.width = 60;
	temp.height = 61;
	animation.push_back(temp);

	temp.left = 26;
	temp.top = 0;
	temp.width = 43;
	temp.height = 62;
	animation.push_back(temp);

	temp.left = 205;
	temp.top = 1;
	temp.width = 65;
	temp.height = 63;
	animation.push_back(temp);

	temp.left = 395;
	temp.top = 12;
	temp.width = 68;
	temp.height = 41;
	animation.push_back(temp);

	temp.left = 588;
	temp.top = 0;
	temp.width = 66;
	temp.height = 63;
	animation.push_back(temp);
}
*/



/*
functions related to the animation
int Tank::determineType(float angle)
{
	int index;
	if (angle == 0)
		index = 0;
	if (angle == 45)
		index = 1;
	if (angle == 90)
		index = 2;
	if (angle == 135)
		index = 3;
	if (angle == 180)
		index = 4;
	if (angle == 225)
		index = 5;
	if (angle == 270)
		index = 6;
	if (angle == 315)
		index = 7;
	return index;
}

if (ROTATION_ANGLES)
	//{
	//	int index = determineType(global_rotation);
		//IntRect animation_t = animation[index];
	//	baseptr->changeAnimation(tank,animation_t);
	//}
	checkRotation();

	void Tank::checkRotation()
{
	if (global_rotation > 359)
		global_rotation = 0;
	if (global_rotation < 0)
		global_rotation = 359;
}
*/