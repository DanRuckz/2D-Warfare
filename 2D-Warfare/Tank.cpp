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
	
	if (rotation >= 0 && rotation <= 90)
	{
		whereto.x = rotation /6;
		whereto.y = 15.f - rotation/6;
	}
	//if (rotation == 90)
	//{
	//	whereto.x = 15.f;
	//	whereto.y = 0.f;
	//}
	if (rotation == 180)
	{
		whereto.x = 0.f;
		whereto.y = -15.f;
	}
	if (rotation == 270)
	{
		whereto.x = -15.f;
		whereto.y = 0.f;
	}


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
