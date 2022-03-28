#include "Map.h"



Map::Map()
{
}

std::vector<Sprite*> Map::getMapVec()
{
	return mapvec;
}

RectangleShape & Map::getBoundingRect()
{
	return mapBoundingRectangle;
}

Vector2f Map::getMapSize()
{
	return mapSize;
}


Map::~Map()
{
}

void Map::CreateMap()
{
	mymap = "assets/Map/MapRect.png";
	texture.loadFromFile(mymap);
	if (!texture.loadFromFile(mymap))
	std::cout << "failed to load texture\n";
	obj_size.x = 125; 
	obj_size.y = 122;
	mapBoundingRectangle.setPosition(Vector2f(0, 0));
	mapBoundingRectangle.setSize(Vector2f(obj_size.x * numberofTiles, obj_size.y*numberofTiles));
	mapBoundingRectangle.setOutlineColor(Color::Black);
	mapBoundingRectangle.setOutlineThickness(5);
	mapobj.setTexture(texture);
	mapobj.setTextureRect(IntRect(Vector2i(0,0), Vector2i(125, 122)));
	for (int i = 0; i < numberofTiles; i++)
	{
		for (int j = 0; j < numberofTiles; j++)
		{
			map = new Sprite;
			map->setTexture(*mapobj.getTexture());
			map->setTextureRect(mapobj.getTextureRect());
			map->setPosition(Vector2f((float)obj_size.x*j, (float)obj_size.y*i));
			mapvec.push_back(map);
		}
	}
	mapSize = Vector2f(obj_size.x * numberofTiles, obj_size.y * numberofTiles);
}

void Map::clearMapVec(){
    while(!mapvec.empty()) {
        delete mapvec.back();
        mapvec.pop_back();
    }
}