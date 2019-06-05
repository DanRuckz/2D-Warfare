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
	
	~Entities();

private:
	static std::vector<Texture*> textures;
	int checkType(std::string);
	void loadTextures();
	void setTexture();
};

