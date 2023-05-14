#include "Map.h"



Map::Map(){
}

std::vector<Sprite*> Map::getMapVec(){
	return mapvec;
}

RectangleShape & Map::getBoundingRect(){
	return mapBoundingRectangle;
}

Vector2f Map::getMapSize(){
	return mapSize;
}


Map::~Map(){
}

void Map::CreateMap(){
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

	for (uint i = 0; i < numberofTiles; i++){
		for (uint j = 0; j < numberofTiles; j++){
			map = new Sprite;
			map->setTexture(*mapobj.getTexture());
			map->setTextureRect(mapobj.getTextureRect());
			map->setPosition(Vector2f((float)obj_size.x*j, (float)obj_size.y*i));
			mapvec.push_back(map);
		}
	}
	mapSize = Vector2f(obj_size.x * numberofTiles, obj_size.y * numberofTiles);
	fill_half_sectors(obj_size.x * numberofTiles, obj_size.y * numberofTiles);
}


//max_depth
//elements per leaf
//numofleafs
void Map::fill_half_sectors(uint x, uint y){

	static uint iteration = 0;
	iteration +=1;
	auto check_even = [](uint number){
		if(number%2!=0){
			return number + 1;
		}
		return number;
	};
	auto divide_two = [](uint number){
		return number/2;
	};
	x = check_even(x);
	x = divide_two(x);
	y = check_even(y);
	y = divide_two(y);
	
	if(x>=obj_size.x *sectorSize){
		//half_sector_points[iteration]["x"] = x;
		//half_sector_points[iteration]["y"] = y;
		std::cout << x << ", " << y << '\n';
		fill_half_sectors(x, y);
	}
	
}


void Map::clearMapVec(){
    while(!mapvec.empty()) {
        delete mapvec.back();
        mapvec.pop_back();
    }
}