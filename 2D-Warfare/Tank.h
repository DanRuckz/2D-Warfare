#pragma once
#include "Playables.h"
#include "Turret.h"
#include "TankShell.h"

class Tank :
	public Playables
{
public:
	Tank();
	void Fire();
	
	~Tank();
	Sprite& getTopPart();
	void rotateEntity(std::string);
	std::shared_ptr<Projectiles> getPointerToProjectile();
	Sprite & getShell();
	void moveEntity(std::string);
	Sprite& getEntity();
	void rotateTurret(Vector2f mousepos,Vector2f tankpos);
	std::string getType();
	void setSelfIndex(int index);
	float getSpeed();
	int getSelfIndex();
	float checkIntersectionWithObjects(std::shared_ptr<Projectiles> pointer, int selfObjectIndex);
	void reduceDamage(float damage);
	float getHP() const; 
	void setPlayer(bool other);
	bool getPlayer() const;
	std::vector<std::shared_ptr<Projectiles>>& getProjectileVector();
	void projectileFly(int index);
	void setRandomPosition();
	void setHP(float Hp);
	int getID();
	void setTarget(Sprite& other);
	float getRadiusofMountPoint();
	Sprite& getTarget();

private:
	Turret turret;
	float offset_x = -1;
	float offset_y = -3;
	Sprite tank;
	IntRect animation;
	float rotateSpeed = 5;
	Playables* baseptr;
	float speed;
	float radius = 1;
	float projectileMax = 3000;
	std::shared_ptr<TankShell> shell;
	unsigned int barrelLength = 55;
	std::string type;
	int selfIndex;
	float HP = 3000;
	bool Player;
	std::vector < std::shared_ptr<Projectiles>> projectiles;
	int ID;
	void setID();
	Sprite target;
	float radiusofMountPoint = 1;
};

