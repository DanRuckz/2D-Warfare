#include "Map.h"



Map::Map()
{
	CreateMap();
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
	map.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(127, 289)));
}
