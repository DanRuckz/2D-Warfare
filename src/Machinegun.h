#include "Projectiles.h"
class Machinegun : public Projectiles
{

public:
	Machinegun();
	void Fly(Sprite& projectile);
	void setPositionOfShot(Vector2f position);
	void setRotationOfShot(float angle);
	Sprite& getSprite();
	void setFlightDirection(Vector2f vector);
	float getDamage() const;
	float getRange();
	std::string getType();
	~Machinegun();
private:
	Projectiles* baseptr;
	Sprite shell;
	IntRect animation;
	float speed;
	std::string type;
	Vector2f direction;
	float damage =	50;
	float maxRange = 1000;
};

