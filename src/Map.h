#pragma once
#include "inits.h"
class Map
{
public:
	Map();
	std::vector<Sprite*> getMapVec();
	RectangleShape& getBoundingRect();
	static Vector2f getMapSize();
	void CreateMap();
	void clearMapVec();
	~Map();
private:
	uint sectorSize = 5;
	Texture texture;
	Sprite mapobj;
	std::vector <Sprite*> mapvec;
	Sprite* map;
	std::string mymap;
	Vector2i obj_size;
	RectangleShape mapBoundingRectangle;
	unsigned int numberofTiles = 50;
	static Vector2f mapSize;
	void fill_half_sectors(uint, uint);
	std::map<uint, std::map<std::string, uint>> half_sector_points;
};

