#ifndef TURRETS_H
#define TURRETS_H
#include "Turrets.h"
class AATurret :
	public Turrets
{
public:
	AATurret();
	Sprite& getTurretSprite();
	void rotateTurret(Vector2f& mousepos, Vector2f& tankpos);
	//void setTurretPos(Vector2f turretpos);
	float getRotateSpeed();
	~AATurret();

private:
	Sprite turretSprite;
	float offset_x = -1;
	float offset_y = 12;
	Turrets* baseptr;
	float speed;
	Vector2f turretpos;
	IntRect animation;
	float rotateSpeed;
};

#endif