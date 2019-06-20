#pragma once
#include "inits.h"
#include "Entities.h"
#include "Playables.h"
#include "Map.h"
class HighScore : public Entities
{
public:
	HighScore();
	Clock& getPlayTimer();
	Time& getPlayTime();
	void updateScore();
	void scorePosition();
	Text & getHighScore();
	Text & gettopHighScore();
	void setEntityPtr(Playables* newptr);
	~HighScore();

private:
	Entities* baseptr;
	Clock playTimer;
	Time playTime;
	Text highScore;
	Text topHighScore;
	Text timeSurvived;
	Playables* entity;
};

