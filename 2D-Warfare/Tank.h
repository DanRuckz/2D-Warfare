#pragma once
#include "Entities.h"
class Tank :
	public Entities
{
public:
	Tank();
	~Tank();
	Sprite getTank();
	void moveTank(std::string);
	void rotateTank(std::string);

private:
	void makeEntity();
	Texture texture;
	Sprite tank;
	void setEntity();
	float speed = 15.f;

};

