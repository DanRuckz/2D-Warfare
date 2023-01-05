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
	//0
	loadFile = "assets/Playables/Tank/0.png";
	setTexture();
	//1
	loadFile = "assets/Playables/AA/1.png";
	setTexture();
	//2
	loadFile = "assets/Playables/Hind/2.png";
	setTexture();
	//3
	loadFile = "assets/Projectiles/3.png";
	setTexture();
	//4
	loadFile = "assets/Props/respawn.jpg";
	setTexture();
	//5
	loadFile = "assets/Props/pickText.png";
	setTexture();
	//6
	loadFile = "assets/Props/MainBackground.png";
	setTexture();
	//7
	loadFile = "assets/Props/arrowUp.png";
	setTexture();
	//8
	loadFile = "assets/Props/arrowDown.png";
	setTexture();
	//9
	loadFile = "assets/Props/Play.png";
	setTexture();
	//10
	loadFile = "assets/Props/Exit.png";
	setTexture();
	//11
	loadFile = "assets/Props/players.png";
	setTexture();
	//12
	loadFile = "assets/Props/rect.png";
	setTexture();
	
	loadFile = "assets/Fonts/TravelingTypewriter.ttf";
	setFont();
}

//some kung fu for loading texture only one time
void Entities::setTexture()
{
	texture = new Texture;
	if (!texture->loadFromFile(loadFile))
		std::cout << "failed to load texture " << std::endl;
	textures.push_back(texture);
}

void Entities::setFont()
{
	font = new Font;
	if (!font->loadFromFile(loadFile))
	{
		std::cout << "failed to load font " << std::endl;
	}
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
	if (type == "respawn")
		index = 4;
	if (type == "PickText")
		index = 5;
	if (type == "mainScreen")
		index = 6;
	if (type == "arrowUp")
		index = 7;
	if (type == "arrowDown")
		index = 8;
	if (type == "Play")
		index = 9;
	if (type == "Exit")
		index = 10;
	if (type == "players")
		index = 11;
	if (type == "rect")
		index = 12;
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


void Entities::setEntity(Text& text, float size)
{
	text.setFont(*font);
	text.setCharacterSize(size);
}

