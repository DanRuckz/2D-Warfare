#pragma once
#include "Entities.h"
#include "Projectiles.h"
class Playables :
	public Entities
{
public:
	Playables();
	//movement and rotation based on direction
	virtual void moveEntity(std::string)=0;
	virtual void rotateEntity(std::string)=0;
	virtual void rotateTurret(Vector2f mousepos, Vector2f tankpos);
	virtual void rotateTurret();
	virtual Sprite& getEntity() =0;
	virtual Sprite& getTopPart() =0;
	virtual void Fire() = 0;
	virtual Sprite& getShell() = 0;
	virtual void projectileFly() = 0;
	virtual Projectiles* getPointerToProjectile()=0;
	//void setRandomPosition(Sprite& entity);
	void setObjectsVector(std::vector<Playables*>& other);
	//taking receiving information from the class and sending this information to the actual function
	void rotateEntity(Sprite & entity, std::string direction, float rotateSpeed);
	void moveEntity(Sprite& entity, std::string direction, float angle, float speed);
	bool checkIntersectionWithObjects(Projectiles * pointer);
	static std::vector<Playables*>& setObjectsVector();
	virtual ~Playables();

private:
	static std::vector<Playables*> objects;
	Sprite placeholder;
};

