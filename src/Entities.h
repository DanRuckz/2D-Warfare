#include "inits.h"
#define M_PI 3.14159265358979323846
#ifndef ENTITIES
#define ENTITIES
class Entities
{
public:
	std::string loadFile;
	static bool loaded;
	static Texture* texture;
	Entities();
	void setEntity(Sprite & entity, Vector2f position, IntRect animation,std::string type);
	void setEntity(Text & text,float size);
	virtual ~Entities();

private:
	static std::vector<Texture*> textures;
	int checkType(std::string);
	void loadTextures();
	void setTexture();
	void setFont();
	static Font* font;
};

#endif