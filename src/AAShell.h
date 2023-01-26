#include "Projectiles.h"
class AAShell :
	public Projectiles
{
public:
	AAShell();
	void Fly(Sprite& projectile) ;
	void setPositionOfShot(Vector2f position);
	void setRotationOfShot(float angle);
	Sprite& getSprite();
	void setFlightDirection(Vector2f vector);
	float getDamage() const;
	float getRange();
	std::string getType();
	~AAShell();
private:
	Projectiles* baseptr;
	Sprite shell;
	float speed;
	Vector2f direction;
	IntRect animation;
	float damage = 150;
	float maxRange = 1700;
	std::string type;
};

