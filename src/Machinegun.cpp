#include "Machinegun.h"



Machinegun::Machinegun() : animation(Vector2i(239, 459), Vector2i(5, 7)), speed(70),type("shot")
{
	baseptr = this;
	shell.setScale(2.7, 2.7);
	baseptr->setEntity(shell, Vector2f(0, 0), animation, "projectile");
}

void Machinegun::Fly(Sprite & projectile)
{
	baseptr->Fly(projectile, speed, direction);

}

void Machinegun::setPositionOfShot(Vector2f position)
{
	shell.setPosition(position);
}

void Machinegun::setRotationOfShot(float angle)
{
	shell.setRotation(angle);

}

Sprite & Machinegun::getSprite()
{
	return shell;
}

void Machinegun::setFlightDirection(Vector2f vector)
{
	direction = vector;
}

float Machinegun::getDamage() const
{
	return damage;
}

float Machinegun::getRange()
{
	return maxRange;
}

std::string Machinegun::getType()
{
	return type;
}


Machinegun::~Machinegun()
{
}
