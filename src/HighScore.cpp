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
	highScore.setString("Score: 0");
	topHighScore.setString("Top Score: 0");
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
	Score = playTime.asSeconds() * entity->getKillCount();
	highScore.setString("Score: " + std::to_string(Score));
	if (Score > TopScore)
	{
		TopScore = Score;
		topHighScore.setString("Top Score: " + std::to_string(TopScore));
	}
}

void HighScore::scorePosition()
{
	highScore.setPosition(scoreTextPos);
	topHighScore.setPosition(topScoreTextPos);
	timeSurvived.setPosition(timerTextPos);
}
Text& HighScore::getHighScore()
{
	return highScore;
}

Text& HighScore::gettopHighScore()
{
	return topHighScore;
}

void HighScore::nullifyScore()
{
	Score = 0;
	highScore.setString("0");
}
void HighScore::setEntityPtr(Playables * newptr)
{
	entity = newptr;
}

void HighScore::updateTimePlayed()
{
	timeSurvived.setString(std::to_string((int)playTime.asSeconds()));
}

Text& HighScore::getTimePlayedText()
{
	return timeSurvived;
}

void HighScore::setTextPos(Vector2f& scorepos, Vector2f& topscorepos,Vector2f& timerpos)
{
	scoreTextPos = scorepos;
	topScoreTextPos = topscorepos;
	timerTextPos = timerpos;
	scorePosition();
}

HighScore::~HighScore()
{
}
