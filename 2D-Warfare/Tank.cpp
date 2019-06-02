#include "Tank.h"



Tank::Tank()
{
	makeEntity();
	setEntity();
	
}

void Tank::makeEntity()
{
	if (!texture.loadFromFile("assets/Playables/Tank/8.png"))
	{
		std::cout << "texture load failed " << std::endl;
		return;
	}
	tank.setTexture(texture);
}

void Tank::setEntity()
{
	tank.setPosition(1000.f, 1000.f);
	tank.setOrigin(Vector2f(tank.getTexture()->getSize().x / 2, tank.getTexture()->getSize().y / 2));
}

Tank::~Tank()
{
}

Sprite Tank::getTank()
{
	return tank;
}

void Tank::moveTank(std::string direction)
{

	float rotation = tank.getRotation();
	Vector2f whereto;
	rotation = rotation * M_PI / 180;

	
		whereto.x = 15.f*std::sin(rotation);
		whereto.y = 15.f*std::cos(rotation);
	

	if (direction == "up")
	{

		tank.move(whereto.x,-whereto.y);
	}



	if (direction == "down")
	{
		tank.move(-whereto.x, whereto.y);
	}
}

void Tank::rotateTank(std::string direction)
{
	if (direction == "left")
		tank.rotate(-5);
	if (direction == "right")
		tank.rotate(5);
}
