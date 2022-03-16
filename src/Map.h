#pragma once
#include "inits.h"
class Map
{
public:
	Map();
	std::vector<Sprite*> getMapVec();
	RectangleShape& getBoundingRect();
	static Vector2f getMapSize();
	~Map();
private:
	void CreateMap();
	Texture texture;
	Sprite mapobj;
	std::vector <Sprite*> mapvec;
	Sprite* map;
	std::string mymap;
	Vector2i obj_size;
	RectangleShape mapBoundingRectangle;
	unsigned int numberofTiles = 50;
	static Vector2f mapSize;
};

