#include "Playables.h"



Playables::Playables()
{

}



void Playables::setObjectsVector(std::vector<Playables*>& other)
{
	objects = other;
}

void Playables::rotateEntity(Sprite & entity, std::string direction, float rotateSpeed)
{
	if (direction == "left")
	{
		entity.rotate(-rotateSpeed);
	}
	if (direction == "right")
	{
		entity.rotate(rotateSpeed);
	}
}



void Playables::moveEntity(Sprite& entity, std::string direction, float angle, float speed)
{
	Vector2f whereto;
	angle = entity.getRotation();
	float rotation_radians;
	rotation_radians = angle * M_PI / 180;


	whereto.x = speed * std::sin(rotation_radians);
	whereto.y = speed * std::cos(rotation_radians);


	if (direction == "up")
	{
		entity.move(whereto.x, -whereto.y);
	}



	if (direction == "down")
	{
		entity.move(Vector2f(-whereto.x /1.5, whereto.y/1.5));
	}
}

void Playables::rotateTurret(Vector2f mousepos, Vector2f tankpos)
{
}

void Playables::rotateTurret()
{
}

Sprite & Playables::getEntity()
{
	//for access
	return placeholder;
}
Sprite & Playables::getTopPart()
{
	// for access
	return placeholder;
}
void Playables::projectileFly(std::shared_ptr<Projectiles> projectile, int index, int selfObjectIndex)
{
	projectile->Fly(projectile->getSprite());

	if (projectile->getDistanceTraveled() > radius || projectile->intersectWithMap(projectile->getSprite()) || checkIntersectionWithObjects(projectile, selfObjectIndex))
	{
		projectile.reset();
		Projectiles::getProjectileVector().erase(Projectiles::getProjectileVector().begin() + index);
		Projectiles::getProjectileVector().shrink_to_fit();
	}

}
Entities::~Entities()
{
}


bool Playables::checkIntersectionWithObjects(std::shared_ptr<Projectiles> pointer, int selfObjectIndex)
{
	bool intersection = false;
	for (int i = 0; i < objects.size(); i++)
	{
		if (pointer->intersectWithObjects(pointer->getSprite(), objects[i]->getEntity()) && objects[i]!= objects[selfObjectIndex])
		{
			intersection = true;
			return intersection;
		}
	}
	return intersection;
}

std::vector<Playables*>& Playables::getObjectsVector()
{
	return objects;
}

void Playables::setHitRadius(float other_radius)
{
	radius = other_radius;
}

int Playables::getShotsFired()
{
	return 0;
}

void Playables::nullifyShotsFired()
{
}

void Playables::sortbyType()
{
	static std::vector<Playables*> temp;
	
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->getType() != "Hind")
			temp.push_back(objects[i]);
	}
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->getType() == "Hind")
			temp.push_back(objects[i]);
	}
	objects = temp;
}

Playables::~Playables()
{
}
