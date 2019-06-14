#include "RespawnScreen.h"


RespawnScreen::RespawnScreen(Vector2f& position) : animation(Vector2i(0, 0), Vector2i(1280, 720))
{
	int x = 400;
	int y = 20;
	float offset_x = 1;
	float offset_y = -70;
	if (position == Vector2f(0, 0))
		position = Vector2f(2000, 2000);

	sprite.setColor(Color(255, 255, 255, 200));
	setEntity(sprite, position, animation, "respawn");

	setEntity(tank, Vector2f((sprite.getPosition().x - x), (sprite.getPosition().y - y)), IntRect(Vector2i(28, 97), Vector2i(34, 59)), "tank");
	setEntity(aa, Vector2f((sprite.getPosition().x ), (sprite.getPosition().y - y)), IntRect(Vector2i(7, 3), Vector2i(36, 79)), "AA");
	setEntity(hind, Vector2f((sprite.getPosition().x + x), (sprite.getPosition().y - y)), IntRect(Vector2i(524, 0), Vector2i(28,62)), "hind");
	
	setEntity(tankTurret, Vector2f(tank.getPosition().x + offset_x , tank.getPosition().y + offset_y), IntRect(Vector2i(31, 276), Vector2i(28, 59)), "tank_turret");
	setEntity(aaTurret, Vector2f(aa.getPosition().x-1, aa.getPosition().y+12), IntRect(Vector2i(12, 163), Vector2i(27, 54)), "AA_turret");
	setEntity(hindBlades, Vector2f(hind.getPosition().x, hind.getPosition().y - 18), IntRect(Vector2i(63, 68), Vector2i(54, 51)), "hind_blades");

	setEntity(title, Vector2f(sprite.getPosition().x , sprite.getPosition().y - 280), IntRect(Vector2i(0, 0), Vector2i(637, 95)), "texts");

	tank.setScale(5.5f, 4.5f);
	tankTurret.setScale(5.4f, 5.4f);

	aa.setScale(3.5f, 3.5f);
	aaTurret.setScale(4.5, 4.5);

	hind.setScale(4.5f, 4.5f);
	hindBlades.setScale(5.5, 5.5);

	title.setScale(1.5, 1.2);
	

}

Sprite & RespawnScreen::getSprite()
{	
	return sprite;
}

Sprite & RespawnScreen::getTankSprite()
{
	return tank;
}

Sprite & RespawnScreen::getHindSprite()
{
	
	return hind;
}

Sprite & RespawnScreen::getTankTurretSprite()
{
	return tankTurret;
}

Sprite & RespawnScreen::getAATurretSprite()
{
	return aaTurret;
}

Sprite & RespawnScreen::getHindBladesSprite()
{
	return hindBlades;
}

Sprite & RespawnScreen::getAASprite()
{
	return aa;
}



RespawnScreen::RespawnScreen() 
{

}


Sprite & RespawnScreen::getTitleSprite()
{
	return title;
}

RespawnScreen::~RespawnScreen()
{
}
