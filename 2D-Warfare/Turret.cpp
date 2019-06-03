#include "Turret.h"

Turret::Turret()
{
	makeEntity();
	setEntity();

}


Sprite& Turret::getTurret()
{
	return turretSprite;
}

void Turret::turretMove(Vector2f position)
{
	turretSprite.setPosition(position);
}

void Turret::rotateTurret(Vector2f mousepos, Vector2f tankpos)
{
	Vector2f P1;
	Vector2f P2;
	float rotation;
	float dot;
	float norm;
	float result;
	P1.x = 0;
	P1.y = 1;
	if (mousepos.y > tankpos.y)
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
	norm =(sqrt(P1.x)*(P1.x) + (P1.y)*(P1.y)) * sqrt((P2.x)*(P2.x) + (P2.y)*(P2.y));
	result = dot / norm;
	if(mousepos.x >= tankpos.x)
	rotation = std::acos(result);
	else rotation = -std::acos(result);
	rotation = rotation * 180 / M_PI;
	turretSprite.setRotation(rotation);
}

void Turret::makeEntity()
{
	if (!texture.loadFromFile("assets/Playables/Tank/0.png"))
	{
		std::cout << "texture load failed " << std::endl;
		return;
	}
	turretSprite.setTexture(texture);
	turretSprite.setTextureRect(IntRect(Vector2i(30,276),Vector2i(31,60)));
}

void Turret::setEntity()
{
	turretSprite.setOrigin(Vector2f(turretSprite.getTextureRect().width / 2, turretSprite.getTextureRect().height / 2 - offset_y));
}

Turret::~Turret()
{
}
