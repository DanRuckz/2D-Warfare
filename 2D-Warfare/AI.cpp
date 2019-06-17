#include "AI.h"



AI::AI() : rotateSpeed(1)
{
	gen.seed(std::random_device()());
}

float AI::measureDistance(Sprite & first, Sprite & second)
{
	Vector2f vector;
	float result;
	vector.x = second.getPosition().x - first.getPosition().x;
	vector.x *= vector.x;
	vector.y = second.getPosition().y - first.getPosition().y;
	vector.y *= vector.y;
	result = std::sqrt(vector.x + vector.y);
	return result;
}

void AI::AIrotateToTarget(Sprite & turret, Vector2f enemypos, Vector2f tankpos)
{
	Vector2f P1;
	Vector2f P2;
	float rotation;
	float dot;
	float norm;
	float result;
	P1.x = 0;
	P1.y = 1;
	if (enemypos.y >= tankpos.y)
	{
		P2.x = abs(enemypos.x - tankpos.x);
		P2.y = -abs(enemypos.y - tankpos.y);
	}
	if (enemypos.y < tankpos.y)
	{

		P2.x = abs(enemypos.x - tankpos.x);
		P2.y = abs(enemypos.y - tankpos.y);
	}

	dot = (P1.x*P2.x + P1.y * P2.y);
	norm = (sqrt(P1.x)*(P1.x) + (P1.y)*(P1.y)) * sqrt((P2.x)*(P2.x) + (P2.y)*(P2.y));
	result = dot / norm;
	if (enemypos.x >= tankpos.x)
		rotation = std::acos(result);
	else rotation = -std::acos(result);
	rotation = rotation * 180 / M_PI;

	if (rotation < 0)
		rotation = 360 + rotation;
	
	turret.setRotation(rotation);
}

void AI::AIturretMove(Sprite& entity,Sprite& turret, float radius)
{
	Vector2f whereto;
	float angle = 180 - entity.getRotation();
	float radians = -angle * M_PI / 180;
	whereto.x = radius * std::sin(radians);
	whereto.y = -radius * std::cos(radians);
	turret.setPosition(entity.getPosition().x + whereto.x, entity.getPosition().y + whereto.y);
}

void AI::AImove()
{
	

	generalClock.restart();
	float distance = 1000000;
	for (int i = 0; i < Playables::getObjectsVector().size(); i++)
	{
		distance = 1000000;
		for (int j = 0; j < OBJ.size(); j++)
		{
			if (!OBJ[i]->getPlayer() && OBJ[i]->getID() != OBJ[j]->getID())
			{
				if(measureDistance(OBJ[i]->getEntity(), OBJ[j]->getEntity()) < distance)
				{
					distance = measureDistance(OBJ[i]->getEntity(), OBJ[j]->getEntity());
					OBJ[i]->setTarget(OBJ[j]->getEntity());
				}

				if (OBJ[i]->getType() != "Hind")
				{
					AIrotateToTarget(OBJ[i]->getTopPart(), OBJ[i]->getTarget().getPosition(),OBJ[i]->getEntity().getPosition());
				}
				
				generalTime = generalClock.getElapsedTime();

					if (dist(gen) % 2 == 0)
					{
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "left", 1);
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());

					}
					else {
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "right", 1);
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					}
					
					//OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", 1, OBJ[i]->getSpeed());

				if (OBJ[i]->getType() == "Tank" && OBJ[j]->getType() == "Hind")
				{
					//fire secondary
				}
			
			}
		}
	}
}


AI::~AI()
{
}

