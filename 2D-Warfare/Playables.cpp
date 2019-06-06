#include "Playables.h"



Playables::Playables()
{

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
		entity.move(-whereto.x /1.5, whereto.y/1.5);
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
Entities::~Entities()
{
}

/*
void Playables::moveEntity(std::string)
{
}

void Playables::rotateEntity(std::string)
{
}


void Playables::rotateTurret(Vector2f mousepos, Vector2f tankpos)
{

}
*/


Playables::~Playables()
{
}
