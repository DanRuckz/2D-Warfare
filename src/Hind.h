#include "Playables.h"
#include "HindBlade.h"
#include "HindShell.h"
class Hind :
	public Playables
{
public:
	Hind();
	Sprite& getEntity();
	void moveEntity(std::string);
	void rotateEntity(std::string direction);
	Sprite& getTopPart();
	void Fire();
	Sprite& getShell();
	std::shared_ptr<Projectiles> getPointerToProjectile();
	void rotateTurret();
	float getSpeed();
	std::string getType();
	int getShotsFired();
	void nullifyShotsFired();
	void setSelfIndex(int index);
	int getSelfIndex();
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
	Sprite* getTarget();
	float getRotateSpeed();
	float getRadiusofMountPoint();
	int getRandomMode();
	void setRandomMode(int other);
	void switchRandomMode(bool other);
	bool getModeSwitcher();
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
	bool getReloading();
	bool getNearEdge();
	void setNearEdge(bool option);
	~Hind();

private:
	IntRect animation;
	float speed;
	std::string type;
	float rotateSpeed;
	Playables* baseptr;
	Sprite hind;
	HindBlade hindblade;
	float barrelLength = 40;
	std::shared_ptr<HindShell> shell;
	int shotsFired = 0;
	int selfIndex;
	float HP = 1000;
	bool Player = false;
	std::vector < std::shared_ptr<Projectiles>> projectiles;
	int ID;
	void setID();
	Sprite * target;
	float radiusofMountPoint = 1;
	int randomMode;
	bool switchMode = true;
	Clock timerofShot;
	Time timeofShot;
	Clock timerBetweenShots;
	Time timeBetweenShots;
	float visibleArea = 1300;
	Clock attackTimer;
	Time attackTime;
	int killCount = 0;
	int lastDamaged;
	Text HPText;
	int HPoffset_x = -45;
	int HPoffset_y = -150;
	std::string targetType;
	bool reloading;
	bool nearEdge = false;
};

