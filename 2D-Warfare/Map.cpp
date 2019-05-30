#include "Map.h"



Map::Map()
{
	CreateMap();
}

std::vector<Sprite*> Map::getMapVec()
{
	return mapvec;
}


Map::~Map()
{
}

void Map::CreateMap()
{
	mymap = "assets/MapRect.png";
	texture.loadFromFile(mymap);
	if (!texture.loadFromFile(mymap))
	std::cout << "failed to load texture\n";
	obj_size.x = 125; 
	obj_size.y = 122;
	mapobj.setTexture(texture);
	mapobj.setTextureRect(IntRect(Vector2i(0,0), Vector2i(125, 122)));
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			map = new Sprite;
			map->setTexture(*mapobj.getTexture());
			map->setTextureRect(mapobj.getTextureRect());
			map->setPosition(Vector2f(obj_size.x*j, obj_size.y*i));
			mapvec.push_back(map);
		}
	}
}
