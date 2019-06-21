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



void Playables::moveEntity(Sprite& entity, std::string direction, float speed)
{
	Vector2f whereto;
	float angle = entity.getRotation();
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
void Playables::fireMachinegun()
{
}
void Playables::projectileFly(std::vector<std::shared_ptr<Projectiles>>& projectilevec, std::shared_ptr<Projectiles> projectile, int index, int selfObjectIndex)
{
	projectile->Fly(projectile->getSprite());
	bool objects = true;
	if (projectile->getDistanceTraveled() > OBJ[selfObjectIndex]->getHitRadius() || projectile->intersectWithMap(projectile->getSprite()))
	{
		objects = false;
		projectile.reset();
		projectilevec.erase(projectilevec.begin() + index);
		projectilevec.shrink_to_fit();
	}

	if (objects)
	{
		float objindex;
		if (checkIntersectionWithObjects(projectile, selfObjectIndex) != -1)
		{
			objindex = checkIntersectionWithObjects(projectile, selfObjectIndex);
			OBJ[objindex]->reduceDamage(projectilevec[index]->getDamage());
			OBJ[objindex]->setLastDamaged(OBJ[selfObjectIndex]->getID());
			projectile.reset();
			projectilevec.erase(projectilevec.begin() + index);
			projectilevec.shrink_to_fit();
		}
	}
}
Entities::~Entities()
{
}


float Playables::checkIntersectionWithObjects(std::shared_ptr<Projectiles> pointer, int selfObjectIndex)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (pointer->intersectWithObjects(pointer->getSprite(), objects[i]->getEntity()) && objects[i]!= objects[selfObjectIndex])
		{
			return i;
		}
	}
	return -1;
}

std::vector<Playables*>& Playables::getObjectsVector()
{
	return objects;
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
	temp.clear();
}



void Playables::AImove()
{
}


bool Playables::getReloading()
{
	return false;
}

Playables::~Playables()
{
}

Turrets * Playables::getTurretPointer()
{
	return nullptr;
}

void Playables::setLastDamaged(int ID)
{
	lastDamaged= ID;
}

void Playables::setHPText(Text & first, Text & other)
{
	first = other;
}
