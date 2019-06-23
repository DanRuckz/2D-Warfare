#include "AAShell.h"



AAShell::AAShell() : animation(Vector2i(6,280),Vector2i(21,4)), speed(100), type("shell")
{
	baseptr = this;
	baseptr->setEntity(shell, Vector2f(0, 0), animation, "projectile");
	shell.setScale(1.5, 1.5);

}

void AAShell::Fly(Sprite & projectile)
{
	baseptr->Fly(projectile, speed, direction);
}

void AAShell::setPositionOfShot(Vector2f position)
{
	shell.setPosition(position);
}

void AAShell::setRotationOfShot(float angle)
{
	shell.setRotation(angle);
}

Sprite & AAShell::getSprite()
{
	return shell;
}

void AAShell::setFlightDirection(Vector2f vector)
{
	direction = vector;
}

float AAShell::getDamage() const
{
	return damage;
}

float AAShell::getRange()
{
	return maxRange;
}

std::string AAShell::getType()
{
	return type;
}


AAShell::~AAShell()
{
}
