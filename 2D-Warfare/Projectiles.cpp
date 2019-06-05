#include "Projectiles.h"



Projectiles::Projectiles()
{
}


void Projectiles::Fly(Sprite & projectile,Vector2f direction)
{
	projectile.move(speed*direction);
}

Vector2f Projectiles::calculateDirection(Sprite& shell, float BarrelLength)
{
	Vector2f vector;
	float radians;
	float angle = shell.getRotation();
	radians = angle * M_PI / 180;
	vector.x = std::cos(radians);
	vector.y = std::sin(radians);
	return vector;
}


Projectiles::~Projectiles()
{
}
