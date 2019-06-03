#pragma once
#include "Entities.h"
class Turret :
	public Entities
{
public:
	Turret();
	Sprite& getTurret();
	void turretMove(Vector2f);
	void rotateTurret(Vector2f,Vector2f);
	~Turret();

private:
	void makeEntity();
	Texture texture;
	Sprite turretSprite;
	void setEntity();
	float offset_x = -1;
	float offset_y = -14;
};

