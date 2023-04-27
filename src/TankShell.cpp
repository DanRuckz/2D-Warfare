#include "TankShell.h"


TankShell::TankShell() : animation(Vector2i(40,54),Vector2i(25,9)),speed(80),type("shell")
{
	baseptr = this;
	baseptr->setEntity(shell, Vector2f(0, 0), animation, "projectile");
}

void TankShell::setPositionOfShot(Vector2f position)
{
	shell.setPosition(position);
}

void TankShell::setRotationOfShot(float angle)
{
	shell.setRotation(angle);
}	

Sprite& TankShell::getSprite()
{
	return shell;
}

void TankShell::Fly(Sprite& projectile)
{
	baseptr->Fly(projectile, speed, direction);
}

void TankShell::setFlightDirection(Vector2f vector)
{
	direction = vector;
}

float TankShell::getDamage() const
{
	return damage;
}

float TankShell::getRange()
{
	return maxRange;
}

std::string TankShell::getType()
{
	return type;
}


TankShell::~TankShell()
{

}
