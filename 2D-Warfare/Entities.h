#pragma once
#include "inits.h"
#include <cmath>
#define M_PI 3.14159265358979323846
class Entities
{
public:
	std::string loadFile;
	static bool loaded;
	static Texture* texture;
	Entities();
	void setEntity(Sprite & entity, Vector2f position, IntRect animation,std::string type);
	Vector2f getEntitiyPosition(Sprite&);
	void moveEntity(Sprite&, std::string, float, float, Sprite&, float, float);
	void rotateEntity(Sprite & entity, std::string direction, float rotateSpeed);
	//virtual void moveEntity(Sprite&, std::string, float, float);
	void rotateTurret(Sprite& turret, Vector2f mousepos, Vector2f tankpos);
	~Entities();

private:
	static std::vector<Texture*> textures;
	int checkType(std::string);
	void loadTextures();
	void setTexture();


};

