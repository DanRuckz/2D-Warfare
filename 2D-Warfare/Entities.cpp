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
	loadFile = "assets/Projectiles/3.png";
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


int Entities::checkType(std::string type)
{
	int index;
	if (type == "tank" || type == "tank_turret")
		index = 0;
	if (type == "AA" || type == "AA_turret")
		index = 1;
	if (type == "hind" || type == "hind_blades")
		index = 2;
	if (type == "projectile")
		index = 3;
	return index;
}


void Entities::setEntity(Sprite& entity, Vector2f position, IntRect animation, std::string type)
{
	int index = checkType(type);
	entity.setPosition(position);
	entity.setTexture(*textures[index]);
	entity.setTextureRect(animation);
	entity.setOrigin((float)entity.getTextureRect().width / 2, (float)entity.getTextureRect().height / 2);

}




/*void Entities::changeAnimation(Sprite & entity,IntRect animation)
{
	entity.setTextureRect(animation);
	entity.setRotation(0);
	entity.setOrigin(Vector2f(entity.getTextureRect().width / 2, entity.getTextureRect().height / 2));
}
*/