#pragma once
#include "Playables.h"
#include "Turret.h"
#include "TankShell.h"
#define ROTATION_ANGLES  global_rotation == 45 || global_rotation == 90 || global_rotation == 135 || global_rotation == 180 ||global_rotation == 225|| global_rotation == 270 || global_rotation == 315 ||global_rotation == 0

//global_rotation == 0 || global_rotation == 18 || global_rotation == 45 || global_rotation == 72 || 
class Tank :
	public Playables
{
public:
	Tank();
	void Fire();
	~Tank();
	Sprite& getTopPart();
	void rotateEntity(std::string);
	Turret& getTurret();
	Sprite & getShell();
	void moveEntity(std::string);
	Sprite& getEntity();
	void rotateTurret(Vector2f mousepos,Vector2f tankpos);

private:
	Turret turret;
	float offset_x = -1;
	float offset_y = -3;
	Sprite tank;
	IntRect animation;
	float global_rotation = 0;
	float rotateSpeed = 5;
	Playables* baseptr;
	float speed;
	float radius = 1;
	TankShell* shell;
	float barrelLength = 10;
};

