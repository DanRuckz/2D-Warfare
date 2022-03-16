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
	void nullifyScore();
	void setEntityPtr(Playables* newptr);
	void updateTimePlayed();
	Text & getTimePlayedText();
	void setTextPos(Vector2f& scorepos, Vector2f& topscorepos, Vector2f& timerpos);
	~HighScore();

private:
	Entities* baseptr;
	Clock playTimer;
	Time playTime;
	Text highScore;
	Text topHighScore;
	Text timeSurvived;
	Playables* entity;
	int TopScore =0;
	int Score =0;
	View* view;
	float factor;
	Vector2f scoreTextPos;
	Vector2f topScoreTextPos;
	Vector2f timerTextPos;
};

