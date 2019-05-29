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
	std::string mymap("assets/MapRect.png");
	texture.loadFromFile(mymap);
	if (!texture.loadFromFile(mymap))
	std::cout << "failed to load texture\n";
	Vector2f obj_size(144.f, 289.f);
	mapobj.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(144, 289)));
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			map = new Sprite;
			map->setTextureRect(mapobj.getTextureRect());
			map->setPosition(Vector2f(obj_size.x*j, obj_size.y*i));
			mapvec.push_back(map);
		}
	}
	
	
}
