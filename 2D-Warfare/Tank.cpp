#include "Tank.h"

Tank::Tank()
{
	makeEntity();
	setEntity();
}

void Tank::makeEntity()
{
	if (!texture.loadFromFile("assets/Playables/Tank/0.png"))
		std::cout << "failed to load texture " << std::endl;
	saveTextures();
}

void Tank::saveTextures()
{
	IntRect temp;
	temp.left = 27; 
	temp.top = 96; 
	temp.width = 41; 
	temp.height = 62;
	animation.push_back(temp);


	temp.left = 205;
	temp.top = 94;
	temp.width = 63;
	temp.height = 65;
	animation.push_back(temp);


	temp.left = 397;
	temp.top = 107;
	temp.width = 64;
	temp.height = 41;
	animation.push_back(temp);
	
	temp.left = 592;
	temp.top = 97;
	temp.width = 60;
	temp.height = 61;
	animation.push_back(temp);

	temp.left = 26;
	temp.top = 0;
	temp.width = 43;
	temp.height = 62;
	animation.push_back(temp);

	temp.left = 205;
	temp.top = 1;
	temp.width = 65;
	temp.height = 63;
	animation.push_back(temp);

	temp.left = 395;
	temp.top = 12;
	temp.width = 68;
	temp.height = 41;
	animation.push_back(temp);

	temp.left = 588;
	temp.top = 0;
	temp.width = 66;
	temp.height = 63;
	animation.push_back(temp);
}
void Tank::setEntity()
{
	tank.setPosition(1000.f, 1000.f);
	tank.setTexture(texture);
	tank.setTextureRect(animation[0]);
	turret.getTurret().setPosition(tank.getPosition().x + offset_x,tank.getPosition().y -3);
	speed = 15.f;
	tank.setOrigin(tank.getTextureRect().width / 2, tank.getTextureRect().height / 2);
	rotation_p = tank.getRotation();
}

void Tank::changeAnimation(float angle)
{
	int index;
	if (angle == 0)
		index = 0;
	if (angle == 45)
		index = 1;
	if(angle == 90)
		index =2;
	if (angle == 135)
		index = 3;
	if (angle == 180)
		index = 4;
	if (angle == 225)
		index = 5;
	if (angle == 270)
		index = 6;
	if (angle == 315)
		index = 7;
	tank.setTextureRect(animation[index]);
	tank.setRotation(0);
	tank.setOrigin(Vector2f(tank.getTextureRect().width/2, tank.getTextureRect().height/2));
	//	currentTextureIndex = index + 1;
	//if (currentTextureIndex == 0 && direction == "left")
	//	currentTextureIndex = 15;

	//if (currentTextureIndex == 15 && direction == "right")
		//currentTextureIndex = 0;
}

Tank::~Tank()
{
}

Sprite& Tank::getTank()
{
	return tank;
}

Sprite& Tank::getTurretSprite()
{
	return turret.getTurret();
}

void Tank::moveTank(std::string direction)
{
	Vector2f whereto;
	float rotation_radians;
	rotation_radians = rotation_p * M_PI / 180;

	
		whereto.x = speed*std::sin(rotation_radians);
		whereto.y = speed*std::cos(rotation_radians);
	

	if (direction == "up")
	{
		tank.move(whereto.x,-whereto.y);
	}



	if (direction == "down")
	{
		tank.move(-whereto.x, whereto.y);
	}

	turret.turretMove(Vector2f(tank.getPosition().x+offset_x,tank.getPosition().y + offset_y));
}

void Tank::rotateTank(std::string direction)
{
	if (direction == "left")
	{
		rotation_p -= rotateSpeed;
		tank.rotate(-rotateSpeed);
		global_rotation -= rotateSpeed;

	}
	if (direction == "right")
	{
		rotation_p += rotateSpeed;
		tank.rotate(rotateSpeed);
		global_rotation += rotateSpeed;
	}
	checkRotation();

	if (ROTATION_ANGLES)
	{
		changeAnimation(global_rotation);
	}
	

}
Texture& Tank::getCurrentTexture()
{
	//return textures[currentTextureIndex];
	return texture;
}

Turret& Tank::getTurret()
{
	return turret;
}

void Tank::checkRotation()
{
	if (global_rotation > 359)
		global_rotation = 0;
	if (global_rotation < 0)
		global_rotation = 359;
}
