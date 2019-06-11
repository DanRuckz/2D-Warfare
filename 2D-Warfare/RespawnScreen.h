#pragma once
#include "inits.h"
#include "Entities.h"
class RespawnScreen : public Entities
{
public:
	RespawnScreen();
	RespawnScreen(View myView);
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
	RectangleShape rect;
	Texture texture;
	Vector2f screenSize;
	IntRect animation;
	View view;
	Sprite sprite;
	Sprite hind, tank, aa;
	Sprite hindBlades, tankTurret, aaTurret;
	Sprite title;

};

