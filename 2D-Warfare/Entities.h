#pragma once
#include "inits.h"
#include <cmath>
#define M_PI 3.14159265358979323846
class Entities
{
public:
	Entities();
	virtual void makeEntity();
	void setEntity(Sprite & entity, Vector2f position, IntRect animation);
	Vector2f getEntitiyPosition(Sprite&);
	void moveEntity(Sprite&, std::string, float, float, Sprite&,float,float);
	void rotateEntity(Sprite & entity, std::string direction, float rotateSpeed);
	//virtual void moveEntity(Sprite&, std::string, float, float);
	void rotateTurret(Sprite& turret, Vector2f mousepos, Vector2f tankpos);


	~Entities();
private:

protected:
	Texture texture;
};

