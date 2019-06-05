#pragma once
#include "Entities.h"
#include "Projectiles.h"
class Playables :
	public Entities
{
public:
	Playables();
	//movement and rotation based on direction
	virtual void moveEntity(std::string);
	virtual void rotateEntity(std::string);
	virtual void rotateTurret(Vector2f mousepos, Vector2f tankpos);
	virtual void Fire() = 0;
	virtual Sprite& getEntity();
	virtual Sprite& getTopPart();
	virtual Sprite & getShell() = 0;
	//taking receiving information from the class and sending this information to the actual function
	void rotateEntity(Sprite & entity, std::string direction, float rotateSpeed);

	//for testing
	void moveEntity(Sprite& entity, std::string direction, float angle, float speed);

	~Playables();

private: 
	Sprite placeholder;
};

