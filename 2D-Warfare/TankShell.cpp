#include "TankShell.h"


TankShell::TankShell() : animation(Vector2i(40,54),Vector2i(25,9))
{
	baseptr = this;
	baseptr->setEntity(shell, Vector2f(0, 0), animation, "projectile");
}

void TankShell::setPositionOfShot(Vector2f position)
{
	//position.x += turretLength * std::sin(shell.getRotation());
	//position.y += turretLength * std::cos(shell.getRotation());
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

void TankShell::Fly()
{
	baseptr->Fly(shell,speed, direction);
}

void TankShell::setFlightDirection(Vector2f vector)
{
	direction = vector;
}


TankShell::~TankShell()
{

}
