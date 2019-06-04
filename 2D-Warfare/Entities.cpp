#include "Entities.h"



Entities::Entities()
{
	if (!loaded)
	{
		loadTextures();
		loaded = true;
	}
}

void Entities::loadTextures()
{
	loadFile = "assets/Playables/Tank/0.png";
	setTexture();
	loadFile = "assets/Playables/AA/1.png";
	setTexture();
	loadFile = "assets/Playables/Hind/2.png";
	setTexture();
}

//some kung fu for loading texture only one time
void Entities::setTexture()
{
	texture = new Texture;
	if (!texture->loadFromFile(loadFile))
		std::cout << "failed to load texture " << std::endl;
	textures.push_back(texture);
}


Vector2f Entities::getEntitiyPosition(Sprite& entity)
{
	return entity.getPosition();
}

void Entities::moveEntity(Sprite& entity, std::string direction, float angle, float speed, Sprite& turret,float offset_x,float offset_y)
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
		entity.move(-whereto.x, whereto.y);
	}
	//move turret with tank
	turret.setPosition(Vector2f(entity.getPosition().x + offset_x, entity.getPosition().y + offset_y));
}

void Entities::rotateEntity(Sprite & entity, std::string direction, float rotateSpeed)
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

void Entities::rotateTurret(Sprite & turret, Vector2f mousepos, Vector2f tankpos)
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


void Entities::setEntity(Sprite& entity, Vector2f position, IntRect animation, std::string type)
{
	int index = checkType(type);
	entity.setPosition(position);
	entity.setTexture(*textures[index]);
	entity.setTextureRect(animation);
	entity.setOrigin((float)entity.getTextureRect().width / 2, (float)entity.getTextureRect().height / 2);

}

int Entities::checkType(std::string type)
{
	int index;
	if (type == "tank" || type == "tank_turret")
		index = 0;
	if (type == "AA" || type == "AA_turret")
		index = 1;
	if (type == "hind" || type == "hind_blades")
		index = 2;
	return index;
}
Entities::~Entities()
{
}









/*void Entities::changeAnimation(Sprite & entity,IntRect animation)
{
	entity.setTextureRect(animation);
	entity.setRotation(0);
	entity.setOrigin(Vector2f(entity.getTextureRect().width / 2, entity.getTextureRect().height / 2));
}
*/