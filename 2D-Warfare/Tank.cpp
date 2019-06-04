#include "Tank.h"

Tank::Tank() : animation(Vector2i(28,96),Vector2i(36,60))
{
	baseptr = this;
	baseptr->setEntity(tank,Vector2f(1000,1000),animation,"tank");
	speed = 15.f;
	turret.setTankPos(tank.getPosition());
	turret.getTurretSprite().setPosition(tank.getPosition().x + offset_x, tank.getPosition().y - 3);
}



Sprite& Tank::getTank()
{
	return tank;
}

Sprite& Tank::getTurretSprite()
{
	return turret.getTurretSprite();
}

void Tank::moveEntity(std::string direction)
{
	baseptr->moveEntity(tank, direction, tank.getRotation(), speed, turret.getTurretSprite(),offset_x,offset_y);
}

void Tank::rotateEntity(std::string direction)
{
	baseptr->rotateEntity(tank, direction, rotateSpeed);
}


Turret& Tank::getTurret()
{
	return turret;
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