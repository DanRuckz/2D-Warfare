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

bool Projectiles::intersectWithMap(Sprite & shell)
{
	if (shell.getPosition().y <= 0 || shell.getPosition().y >= Map::getMapSize().y)
		return true;
	if (shell.getPosition().x <= 0 || shell.getPosition().x >= Map::getMapSize().x)
		return true;
	return false;
}

bool Projectiles::intersectWithObjects(Sprite & shell, Sprite & object)
{
	if(Collision::PixelPerfectTest(shell,object))
	return true;
	return false;
}

std::vector<std::shared_ptr<Projectiles>>& Projectiles::getProjectileVector()
{
	return projectilesVector;
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
