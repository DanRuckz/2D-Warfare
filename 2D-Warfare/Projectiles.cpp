#include "Projectiles.h"



Projectiles::Projectiles()
{
}


void Projectiles::Fly(Sprite & projectile,float speed, Vector2f direction)
{
	projectile.move(speed*direction);
	distanceTraveled(speed, direction);
}

float Projectiles::getDistanceTraveled()
{
	return m_distanceTraveled;
}

Vector2f Projectiles::calculateDirection(Sprite& shell, float BarrelLength)
{
	Vector2f vector;
	float radians;
	float angle = shell.getRotation();
	radians = angle * M_PI / 180;
	vector.x = BarrelLength * std::cos(radians);
	vector.y = BarrelLength * std::sin(radians);
	return vector;
}

void Projectiles::distanceTraveled(float speed, Vector2f direction)
{
	distanceVector += speed * direction;
	m_distanceTraveled = sqrt(pow(distanceVector.x, 2) + pow(distanceVector.y, 2));
}
Projectiles::~Projectiles()
{
}
