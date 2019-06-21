#pragma once
#include "Playables.h"
#include "Turret.h"
#include "TankShell.h"
#include "Machinegun.h"

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
	void setTarget(Sprite* other);
	float getRadiusofMountPoint();
	float getRotateSpeed();
	Sprite* getTarget();
	int getRandomMode();
	void setRandomMode(int other);
	void switchRandomMode(bool other);
	bool getModeSwitcher();
	Turrets* getTurretPointer();
	float getVisibleArea();
	Clock& getAttackClock();
	Time& getAttackTime();
	int getKillCount();
	void increaseKillCount();
	void setLastDamaged(int ID);
	int getLastDamaged();
	Text& getHPText();
	void updateHPText();
	void setTargetType(std::string type);
	std::string getTargetType();
	void fireMachinegun() override;
	float getHitRadius();


private:
	Turret turret;
	float offset_x = -1;
	float offset_y = -3;
	Sprite tank;
	IntRect animation;
	float rotateSpeed;
	Playables* baseptr;
	float speed;
	float radius = 1;
	float hitRadius = 3000;
	std::shared_ptr<Projectiles> shell;
	unsigned int barrelLength = 70;
	std::string type;
	int selfIndex;
	float HP = 3000;
	bool Player;
	std::vector < std::shared_ptr<Projectiles>> projectiles;
	int ID;
	void setID();
	Sprite* target;
	float radiusofMountPoint = 1;
	int randomMode;
	bool switchMode = true;
	Clock timerofShot;
	Time timeofShot;
	float visibleArea = 1300;
	Clock attackTimer;
	Time attackTime;
	int killCount = 0;
	int lastDamaged;
	Text HPText;
	int HPoffset_x = -45;
	int HPoffset_y = -150;
	std::string targetType;
	Clock timerofMG;
	Time timeofMG;
	std::string lastFired;
};

