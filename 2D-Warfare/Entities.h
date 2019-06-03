#pragma once
#include "inits.h"
#include <cmath>
#define M_PI 3.14159265358979323846
class Entities
{
public:
	Entities();
	virtual void makeEntity() = 0;
	virtual void setEntity() = 0;
	virtual void rotateTurret();
	~Entities();
};

