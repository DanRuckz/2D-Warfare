#include "Projectiles.h"
class HindShell :
	public Projectiles
{
public:
	HindShell();
	void setPositionOfShot(Vector2f position);
	void setRotationOfShot(float angle);
	Sprite & getSprite();
	void Fly(Sprite& projectile);
	void setFlightDirection(Vector2f vector);
	float getDamage() const;
	float getRange();
	std::string getType();
	~HindShell();

private:
	Projectiles* baseptr;
	Sprite shell;
	IntRect animation;
	float speed;
	std::string type;
	Vector2f direction;
	float damage = 200;
	float maxRange = 1700;
};

