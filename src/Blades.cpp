#include "Blades.h"



Blades::Blades() : rotateSpeed(200)
{
}

void Blades::Spin(Sprite& blade)
{
	blade.rotate(rotateSpeed);
}


Blades::~Blades()
{
}
