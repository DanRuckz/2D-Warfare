#include "HindShell.h"



HindShell::HindShell() : animation(Vector2i(206,513),Vector2i(33,9)), speed(50)
{
	baseptr = this;
	baseptr->setEntity(shell, Vector2f(0, 0), animation, "projectile");
	shell.setScale(Vector2f(1.3,1.3));
}

void HindShell::setFlightDirection(Vector2f vector)
{
	direction = vector;
}

float HindShell::getDamage() const
{
	return damage;
}

void HindShell::setPositionOfShot(Vector2f position)
{
	shell.setPosition(position);

}

void HindShell::setRotationOfShot(float angle)
{
	shell.setRotation(angle);
}

Sprite & HindShell::getSprite()
{
	return shell;
}

void HindShell::Fly(Sprite& projectile)
{
	baseptr->Fly(projectile, speed, direction);
}


HindShell::~HindShell()
{
}
