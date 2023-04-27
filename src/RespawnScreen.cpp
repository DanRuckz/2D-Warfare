#include "RespawnScreen.h"


RespawnScreen::RespawnScreen(View& view) : animation(Vector2i(0, 0), Vector2i(RESPAWN_SCREEN_SIZE_X, RESPAWN_SCREEN_SIZE_Y)){
	view.setCenter(Config::getInstance().getResolution().width, Config::getInstance().getResolution().height);
	respawn_screen_position.x = view.getCenter().x/Config::getInstance().getScale().x;
	respawn_screen_position.y = view.getCenter().y/Config::getInstance().getScale().y;
	tank.setScale(5.5f, 4.5f);
	tankTurret.setScale(5.4f, 5.4f);
	aa.setScale(3.5f, 3.5f);
	aaTurret.setScale(4.5, 4.5);
	hind.setScale(4.5f, 4.5f);
	hindBlades.setScale(5.5, 5.5);
	title.setScale(1.5, 1.2);
	respawnScreen.setColor(Color(255, 255, 255, 200));
	setEntity(respawnScreen, respawn_screen_position, animation, "respawn");
	setEntity(tank, {respawn_screen_position.x -400 ,respawn_screen_position.y},
	IntRect(Vector2i(28, 97), Vector2i(34, 59)), "tank");
	setEntity(aa, respawn_screen_position, IntRect(Vector2i(7, 3), Vector2i(36, 79)), "AA");
	setEntity(hind, {respawn_screen_position.x + 400, respawn_screen_position.y}, 
	IntRect(Vector2i(524, 0), Vector2i(28,62)), "hind");
	setEntity(tankTurret, {tank.getPosition().x/Config::getInstance().getScale().x, (tank.getPosition().y-60)/Config::getInstance().getScale().y}, 
	IntRect(Vector2i(31, 276), Vector2i(28, 59)), "tank_turret");
	setEntity(aaTurret, {aa.getPosition().x/Config::getInstance().getScale().x, aa.getPosition().y/Config::getInstance().getScale().y}, 
	IntRect(Vector2i(12, 163), Vector2i(27, 54)), "AA_turret");
	setEntity(hindBlades, {hind.getPosition().x/Config::getInstance().getScale().x, hind.getPosition().y/Config::getInstance().getScale().y}, 
	IntRect(Vector2i(63, 68), Vector2i(54, 51)), "hind_blades");
	setEntity(title, {respawn_screen_position.x, respawn_screen_position.y - RESPAWN_SCREEN_SIZE_Y/2 + 50}, 
	IntRect(Vector2i(0, 0), Vector2i(637, 95)), "PickText");
}

Sprite & RespawnScreen::getSprite()
{	
	return respawnScreen;
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

Sprite & RespawnScreen::getTitleSprite()
{
	return title;
}

RespawnScreen::~RespawnScreen()
{
}
