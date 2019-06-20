#pragma once
#include "Entities.h"
#include "Projectiles.h"
#include "Turret.h"
#include "AATurret.h"
#include <random>
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
	void projectileFly(std::vector<std::shared_ptr<Projectiles>>& projectilevec, std::shared_ptr<Projectiles> projectile,int index, int selfObjectIndex);
	virtual std::shared_ptr<Projectiles> getPointerToProjectile()=0;
	void setObjectsVector(std::vector<Playables*>& other);
	//taking receiving information from the class and sending this information to the actual function
	static void rotateEntity(Sprite & entity, std::string direction, float rotateSpeed);
	static void moveEntity(Sprite& entity, std::string direction, float angle, float speed);
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
	virtual void reduceDamage(float damage) = 0;
	virtual float getHP() const = 0;
	virtual void setPlayer(bool other) = 0;
	virtual bool getPlayer() const = 0;
	virtual std::vector<std::shared_ptr<Projectiles>>& getProjectileVector() = 0;
	virtual void projectileFly(int index) = 0;
	virtual void setRandomPosition() = 0;
	virtual void setHP(float Hp) = 0;
	virtual int getID() = 0;
	virtual void setID() = 0;
	virtual void AImove();
	virtual void setTarget(Sprite& other) = 0;
	virtual Sprite& getTarget() =0;
	virtual float getRadiusofMountPoint() = 0;
	virtual float getRotateSpeed() = 0;
	virtual Turrets* getTurretPointer();
	virtual void setLastDamaged(int ID) =0;
	virtual int getLastDamaged() = 0;
	virtual int getKillCount() = 0;
	virtual void increaseKillCount() = 0;
	//FOR AI

	virtual int getRandomMode() = 0;
	virtual void setRandomMode(int other) = 0;
	virtual bool getModeSwitcher() = 0;
	virtual void switchRandomMode(bool other) = 0;
	virtual float getVisibleArea() = 0;
	virtual Clock& getAttackClock() = 0;
	virtual Time& getAttackTime() = 0;
	virtual ~Playables();

private:
	static std::vector<Playables*> objects;
	Sprite placeholder;
	float radius;
	bool Player;
	int lastDamaged;
protected:
	int ID;
};

