#pragma once
#include "inits.h"
class Map
{
public:
	Map();
	std::vector<Sprite*> getMapVec();
	~Map();
private:
	void CreateMap();
	Texture texture;
	Sprite mapobj;
	std::vector <Sprite*> mapvec;
	Sprite* map;
	std::string mymap;
	Vector2i obj_size;
};

