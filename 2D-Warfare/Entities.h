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
	

	//movement and rotation based on direction
	virtual void moveEntity(std::string);
	virtual void rotateEntity(std::string);

	//taking receiving information from the class and sending this information to the actual function
	void rotateEntity(Sprite & entity, std::string direction, float rotateSpeed);

	//for testing
	void moveEntity(Sprite&, std::string, float, float);


	virtual void rotateTurret(Vector2f mousepos, Vector2f tankpos);
	virtual Sprite& getEntity();
	virtual Sprite& getTopPart();
	~Entities();

private:
	static std::vector<Texture*> textures;
	int checkType(std::string);
	void loadTextures();
	void setTexture();
	Sprite placeholder;


};

