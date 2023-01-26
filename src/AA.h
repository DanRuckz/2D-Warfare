#include "Playables.h"
#include "AATurret.h"
#include "AAShell.h"

class AA : public Playables
{
public:
	AA();
	void moveEntity(std::string);
	void rotateEntity(std::string);
	Sprite & getTopPart();
	Sprite& getEntity();
	void rotateTurret(Vector2f mousepos, Vector2f tankpos);
	void Fire();
	Sprite& getShell();
	std::shared_ptr<Projectiles> getPointerToProjectile();
	float getSpeed();
	std::string getType();
	void setSelfIndex(int index);
	int getSelfIndex();
	void reduceDamage(float damage);
	void setHP(float Hp);
	float getHP() const;
	void setPlayer(bool other);
	bool getPlayer() const;
	std::vector<std::shared_ptr<Projectiles>>& getProjectileVector();
	void projectileFly(int index);
	void setRandomPosition();
	void setTarget(Sprite* other);
	int getID();
	Sprite* getTarget();
	float getRadiusofMountPoint();
	float getRotateSpeed();
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
	bool getNearEdge();
	void setNearEdge(bool option);
	~AA();

private:
	Playables* baseptr;
	IntRect animation;
	Sprite anti_air;
	float speed;
	float rotateSpeed;
	AATurret aaturret;
	float offset_x = 0;
	float offset_y = 23;
	float radiusofMountPoint = 23;
	std::string type;
	std::shared_ptr<AAShell> shell;
	float barrelLength = 23;
	bool left = false;
	int selfIndex;
	float HP = 1500;
	bool Player = false;
	std::vector < std::shared_ptr<Projectiles>> projectiles;
	int ID;
	void setID();
	Sprite* target;
	int randomMode;
	bool switchMode = true;
	Clock timerofShot;
	Time timeofShot;
	float visibleArea = 1200;
	Clock attackTimer;
	Time attackTime;
	int killCount = 0;
	int lastDamaged;
	Text HPText;
	int HPoffset_x = -45;
	int HPoffset_y = -150;
	std::string targetType;
	bool nearEdge = false;

};

