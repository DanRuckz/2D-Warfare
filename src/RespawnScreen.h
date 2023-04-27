#include "inits.h"
#include "Entities.h"
class RespawnScreen : public Entities
{
public:
	RespawnScreen(View&);
	Sprite& getSprite();
	Sprite& getTankSprite();
	Sprite& getAASprite();
	Sprite& getHindSprite();
	Sprite& getTankTurretSprite();
	Sprite& getAATurretSprite();
	Sprite& getHindBladesSprite();
	Sprite& getTitleSprite();
	~RespawnScreen();

private:
	const uint RESPAWN_SCREEN_SIZE_X = 1280;
	const uint RESPAWN_SCREEN_SIZE_Y = 720;
	RectangleShape rect;
	Texture texture;
	Vector2f screenSize;
	IntRect animation;
	Vector2f respawn_screen_position;
	Sprite respawnScreen;
	Sprite hind, tank, aa;
	Sprite hindBlades, tankTurret, aaTurret;
	Sprite title;
	View view;

};

