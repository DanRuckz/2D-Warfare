#pragma once
#include "inits.h"
struct Static_Pipe
{
public:
	 Static_Pipe();
	void setMapSize(Vector2f mapsize);
	static Vector2f getMapSize();
	~Static_Pipe();
private:
	static Vector2f mapSize;
};

