#pragma once
#include "inits.h"
class Entities
{
public:
	Entities();
	virtual void makeEntity() = 0;
	virtual void setEntity() = 0;
	~Entities();
};

