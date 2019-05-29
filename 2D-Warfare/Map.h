#pragma once
#include "inits.h"
class Map
{
public:
	Map();

	~Map();
private:
	void CreateMap();
	Texture texture;
	Sprite map;
	std::vector <Sprite*> mapvec;

};

