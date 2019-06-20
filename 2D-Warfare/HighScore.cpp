#include "HighScore.h"


HighScore::HighScore()
{
	baseptr = this;
	baseptr->setEntity(highScore, 70);
	baseptr->setEntity(topHighScore,70);
	baseptr->setEntity(timeSurvived,70);
	highScore.setFillColor(Color::Black);
	highScore.setStyle(Text::Bold);
	topHighScore.setFillColor(Color::Black);
	topHighScore.setStyle(Text::Bold);
	timeSurvived.setFillColor(Color::Black);
	timeSurvived.setStyle(Text::Bold);
}

Clock & HighScore::getPlayTimer()
{
	return playTimer;
}

Time & HighScore::getPlayTime()
{
	return playTime;
}

void HighScore::updateScore()
{
	int temphighscore = playTime.asSeconds() * entity->getKillCount();
	highScore.setString(std::to_string(temphighscore));
}

void HighScore::scorePosition()
{
	highScore.setPosition(entity->getEntity().getPosition().x, entity->getEntity().getPosition().y - 10);
}
Text& HighScore::getHighScore()
{
	return highScore;
}

Text& HighScore::gettopHighScore()
{
	return topHighScore;
}

void HighScore::setEntityPtr(Playables * newptr)
{
	entity = newptr;
}


HighScore::~HighScore()
{
}
