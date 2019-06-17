#include "Turrets.h"



Turrets::Turrets()
{
}

void Turrets::rotateTurret(Sprite & turret, Vector2f mousepos, Vector2f tankpos)
{
	Vector2f P1;
	Vector2f P2;
	float rotation;
	float dot;
	float norm;
	float result;
	P1.x = 0;
	P1.y = 1;
	if (mousepos.y >= tankpos.y)
	{
		P2.x = abs(mousepos.x - tankpos.x);
		P2.y = -abs(mousepos.y - tankpos.y);
	}
	if (mousepos.y < tankpos.y)
	{

		P2.x = abs(mousepos.x - tankpos.x);
		P2.y = abs(mousepos.y - tankpos.y);
	}

	dot = (P1.x*P2.x + P1.y * P2.y);
	norm = (sqrt(P1.x)*(P1.x) + (P1.y)*(P1.y)) * sqrt((P2.x)*(P2.x) + (P2.y)*(P2.y));
	result = dot / norm;
	if (mousepos.x >= tankpos.x)
		rotation = std::acos(result);
	else rotation = -std::acos(result);
	rotation = rotation * 180 / M_PI;
	turret.setRotation(rotation);
}

void Turrets::moveTurret(Sprite& entity, Sprite& turret,float radius)
{
	Vector2f whereto;
	float angle = 180 - entity.getRotation();
	float radians = -angle * M_PI / 180;
	whereto.x = radius * std::sin(radians);
	whereto.y = -radius * std::cos(radians);
	turret.setPosition(entity.getPosition().x + whereto.x,entity.getPosition().y+  whereto.y);
}



Turrets::~Turrets()
{
}
