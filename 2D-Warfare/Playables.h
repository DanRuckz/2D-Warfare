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
	void projectileFly(std::shared_ptr<Projectiles> projectile,int index, int selfObjectIndex);
	virtual std::shared_ptr<Projectiles> getPointerToProjectile()=0;
	//void setRandomPosition(Sprite& entity);
	void setObjectsVector(std::vector<Playables*>& other);
	//taking receiving information from the class and sending this information to the actual function
	void rotateEntity(Sprite & entity, std::string direction, float rotateSpeed);
	void moveEntity(Sprite& entity, std::string direction, float angle, float speed);
	virtual float checkIntersectionWithObjects(std::shared_ptr<Projectiles> pointer, int selfObjectIndex);
	static std::vector<Playables*>& getObjectsVector();
	void setHitRadius(float other_radius);
	virtual float getSpeed() = 0;
	virtual std::string getType() = 0;
	virtual int getShotsFired();
	virtual void nullifyShotsFired();
	virtual void setSelfIndex(int index) = 0;
	virtual int getSelfIndex()=0;
	static void sortbyType();
	virtual void setHP(float damage) = 0;
	virtual float getHP() const = 0;
	virtual void setPlayer(bool other) = 0;
	virtual bool getPlayer() const = 0;
	virtual ~Playables();

private:
	static std::vector<Playables*> objects;
	Sprite placeholder;
	float radius;
	bool Player;
};

