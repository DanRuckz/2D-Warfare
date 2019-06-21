#include "AI.h"


AI::AI()
{
	gen.seed(std::random_device()());
}

void AI::AImove()
{
	rotateTurretToEnemy();
	searchMode();
	attackMode();
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

float AI::getAngleBetween(Sprite& first, Sprite& second)
	{
	Vector2f P1;
	Vector2f P2;
	float rotation;
	float dot;
	float norm;
	float result;
	P1.x = 0;
	P1.y = 1;
	if (second.getPosition().y >= first.getPosition().y)
	{
		P2.x = abs(second.getPosition().x - first.getPosition().x);
		P2.y = -abs(second.getPosition().y - first.getPosition().y);
	}
	if (second.getPosition().y < first.getPosition().y)
	{

		P2.x = abs(second.getPosition().x - first.getPosition().x);
		P2.y = abs(second.getPosition().y - first.getPosition().y);
	}

	dot = (P1.x*P2.x + P1.y * P2.y);
	norm = (sqrt(P1.x)*(P1.x) + (P1.y)*(P1.y)) * sqrt((P2.x)*(P2.x) + (P2.y)*(P2.y));
	result = dot / norm;
	if (second.getPosition().x >= first.getPosition().x)
		rotation = std::acos(result);
	else rotation = -std::acos(result);
	rotation = rotation * 180 / M_PI;

	if (rotation < 0)
		rotation = 360 + rotation;
	return rotation;
	}

void AI::AIrotateToTarget(Sprite & entity, Sprite& other, Playables* entityObject ,float rotateSpeed)
{
	Vector2f P1;
	Vector2f P2;
	float rotation;
	float dot;
	float norm;
	float result;
	P1.x = 0;
	P1.y = 1;
	if (other.getPosition().y >= entity.getPosition().y)
	{
		P2.x = abs(other.getPosition().x - entity.getPosition().x);
		P2.y = -abs(other.getPosition().y - entity.getPosition().y);
	}
	if (other.getPosition().y < entity.getPosition().y)
	{

		P2.x = abs(other.getPosition().x - entity.getPosition().x);
		P2.y = abs(other.getPosition().y - entity.getPosition().y);
	}

	dot = (P1.x*P2.x + P1.y * P2.y);
	norm = (sqrt(P1.x)*(P1.x) + (P1.y)*(P1.y)) * sqrt((P2.x)*(P2.x) + (P2.y)*(P2.y));
	result = dot / norm;
	if (other.getPosition().x >= entity.getPosition().x)
		rotation = std::acos(result);
	else rotation = -std::acos(result);
	rotation = rotation * 180 / M_PI;
	
	if (rotation < 0)
		rotation = 360 + rotation;

		//ROTATE RIGHT
		if (entity.getRotation() >= 0 && rotation <= entity.getRotation() + 180 && entity.getRotation() < rotation)
		{
			if (measureFloats(rotation, entity.getRotation()) > 4.5)
				entityObject->rotateEntity(entity, "right", rotateSpeed);
		}

		else if (entity.getRotation() >= 180 && rotation > moduluRotation(entity.getRotation() + 180) && entity.getRotation() < rotation)
		{
			entityObject->rotateEntity(entity, "right", rotateSpeed);

		}
		else if (entity.getRotation() >= 180 && rotation >= 0 && rotation < moduluRotation(entity.getRotation() + 180))
		{
			entityObject->rotateEntity(entity, "right", rotateSpeed);
		}

		//ROTATE LEFT
		else if (entity.getRotation() >= 0 && rotation <= entity.getRotation() + 180 && entity.getRotation() > rotation)
		{
			entityObject->rotateEntity(entity, "left", rotateSpeed);
		}

		else if (entity.getRotation() >= 0 && rotation > moduluRotation(entity.getRotation() + 180))
		{
			entityObject->rotateEntity(entity, "left", rotateSpeed);
		}
}

void AI::AIrotateAwayFromTarget(Sprite & entity, Sprite& other, Playables* entityObject, float rotateSpeed)
{
	Vector2f P1;
	Vector2f P2;
	float rotation;
	float dot;
	float norm;
	float result;
	P1.x = 0;
	P1.y = 1;
	if (other.getPosition().y >= entity.getPosition().y)
	{
		P2.x = abs(other.getPosition().x - entity.getPosition().x);
		P2.y = -abs(other.getPosition().y - entity.getPosition().y);
	}
	if (other.getPosition().y < entity.getPosition().y)
	{

		P2.x = abs(other.getPosition().x - entity.getPosition().x);
		P2.y = abs(other.getPosition().y - entity.getPosition().y);
	}

	dot = (P1.x*P2.x + P1.y * P2.y);
	norm = (sqrt(P1.x)*(P1.x) + (P1.y)*(P1.y)) * sqrt((P2.x)*(P2.x) + (P2.y)*(P2.y));
	result = dot / norm;
	if (other.getPosition().x >= entity.getPosition().x)
		rotation = std::acos(result);
	else rotation = -std::acos(result);
	rotation = rotation * 180 / M_PI;

	if (rotation < 0)
		rotation = 360 + rotation;

	//ROTATE RIGHT
	if (entity.getRotation() >= 0 && rotation <= entity.getRotation() + 180 && entity.getRotation() < rotation)
	{
		if (measureFloats(rotation, entity.getRotation()) > 4.5)
			entityObject->rotateEntity(entity, "left", rotateSpeed);
	}

	else if (entity.getRotation() >= 180 && rotation > moduluRotation(entity.getRotation() + 180) && entity.getRotation() < rotation)
	{
		entityObject->rotateEntity(entity, "left", rotateSpeed);

	}
	else if (entity.getRotation() >= 180 && rotation >= 0 && rotation < moduluRotation(entity.getRotation() + 180))
	{
		entityObject->rotateEntity(entity, "left", rotateSpeed);
	}

	//ROTATE LEFT
	else if (entity.getRotation() >= 0 && rotation <= entity.getRotation() + 180 && entity.getRotation() > rotation)
	{
		entityObject->rotateEntity(entity, "right", rotateSpeed);
	}

	else if (entity.getRotation() >= 0 && rotation > moduluRotation(entity.getRotation() + 180))
	{
		entityObject->rotateEntity(entity, "right", rotateSpeed);
	}
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

void AI::searchMode()
{
	generalTime = generalClock.getElapsedTime();
	//std::cout << generalTime.asSeconds() << std::endl;
	for (int i = 0; i < OBJ.size(); i++)
	{
		if (!OBJ[i]->getPlayer() && OBJ[i]->getTarget() == nullptr)
		{
			if (OBJ[i]->getRandomMode() == 0 && OBJ[i]->getEntity().getPosition().y > 30)
			{
				OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "left", OBJ[i]->getRotateSpeed());
				AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
				AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				if (generalTime.asSeconds() > 1)
				{
					OBJ[i]->switchRandomMode(true);
					generalClock.restart();
				}
			}

			if (OBJ[i]->getRandomMode() == 1 && OBJ[i]->getEntity().getPosition().y > 30)
			{
				OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "right", OBJ[i]->getRotateSpeed());
				AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
				AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				if (generalTime.asSeconds() > 1)
				{
					OBJ[i]->switchRandomMode(true);
					generalClock.restart();
				}
			}

			if (OBJ[i]->getRandomMode() == 2 && OBJ[i]->getEntity().getPosition().y > 30)
			{
				OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
				AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				if (generalTime.asSeconds() > 2)
				{
					OBJ[i]->switchRandomMode(true);
					generalClock.restart();
				}
			}

			if (OBJ[i]->getRandomMode() == 3 && OBJ[i]->getEntity().getPosition().y > 30)
			{
				OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "left", OBJ[i]->getRotateSpeed());
				AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				if (generalTime.asSeconds() > 1)
				{
					OBJ[i]->switchRandomMode(true);
					generalClock.restart();
				}
			}
			if (OBJ[i]->getRandomMode() == 4 && OBJ[i]->getEntity().getPosition().y > 30)
			{
				OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "right", OBJ[i]->getRotateSpeed());
				AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				if (generalTime.asSeconds() > 1)
				{
					OBJ[i]->switchRandomMode(true);
					generalClock.restart();
				}
			}


			if (OBJ[i]->getModeSwitcher())
			{
				int random = dist(gen) % 5;
				OBJ[i]->setRandomMode(random);
				OBJ[i]->switchRandomMode(false);
			}
			//UPPER BOUND
			if (OBJ[i]->getEntity().getPosition().y < 95)
			{
				int randomDirection;
				randomDirection = dist(gen) % 2;
				if (randomDirection == 0)
					while (true)
					{
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "left", OBJ[i]->getRotateSpeed());
							AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						if (OBJ[i]->getEntity().getRotation() > 90 && OBJ[i]->getEntity().getRotation() < 270)
							break;
					}
				if (randomDirection == 1)
					while (true)
					{
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "right", OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						if (OBJ[i]->getEntity().getRotation() > 90 && OBJ[i]->getEntity().getRotation() < 270)
							break;
					}
			}

			//LEFT BOUND
			if (OBJ[i]->getEntity().getPosition().x < 95)
			{
				int randomDirection;
				randomDirection = dist(gen) % 2;
				if (randomDirection == 0)
					while (true)
					{
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "left", OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						if (OBJ[i]->getEntity().getRotation() > 0 && OBJ[i]->getEntity().getRotation() < 180)
							break;
					}
				if (randomDirection == 1)
					while (true)
					{
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "right", OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						if (OBJ[i]->getEntity().getRotation() > 0 && OBJ[i]->getEntity().getRotation() < 180)
							break;
					}
			}
			//BOTTOM BOUND
			if (Map::getMapSize().y - OBJ[i]->getEntity().getPosition().y < 95)
			{
				int randomDirection;
				randomDirection = dist(gen) % 2;
				if (randomDirection == 0)
					while (true)
					{
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "left", OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						if (OBJ[i]->getEntity().getRotation() > 270 || OBJ[i]->getEntity().getRotation() < 90)
							break;
					}
				if (randomDirection == 1)
					while (true)
					{
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "right", OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						if (OBJ[i]->getEntity().getRotation() > 270 || OBJ[i]->getEntity().getRotation() < 90)
							break;
					}
			}
			//RIGHT BOUND
			if (Map::getMapSize().x - OBJ[i]->getEntity().getPosition().x < 95)
			{
				int randomDirection;
				randomDirection = dist(gen) % 2;
				if (randomDirection == 0)
					while (true)
					{
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "left", OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						if (OBJ[i]->getEntity().getRotation() < 360 && OBJ[i]->getEntity().getRotation() > 180)
							break;
					}
				if (randomDirection == 1)
					while (true)
					{
						OBJ[i]->rotateEntity(OBJ[i]->getEntity(), "right", OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						if (OBJ[i]->getEntity().getRotation() < 360 && OBJ[i]->getEntity().getRotation() > 180)
							break;
					}
			}
		}

	}		
}


void AI::attackMode()
{
	for (int i = 0; i < OBJ.size(); i++)
	{
		if (OBJ[i]->getTarget() != nullptr)
		{
			if (measureDistance(OBJ[i]->getEntity(), *OBJ[i]->getTarget()) > OBJ[i]->getVisibleArea())
			{
				OBJ[i]->setTarget(nullptr);
				break;
			}
			if (OBJ[i]->getType() == "Tank" && OBJ[i]->getTargetType() == "AA" || OBJ[i]->getType() == "Tank" && OBJ[i]->getTargetType() == "Tank")
			{
				AIrotateToTarget(OBJ[i]->getEntity(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getRotateSpeed());
				AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
				AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				if (measureDistance(OBJ[i]->getEntity(), *OBJ[i]->getTarget()) < 70)
				{

				}
				OBJ[i]->Fire();
				OBJ[i]->fireMachinegun();
			}
				if (OBJ[i]->getType() == "Tank" && OBJ[i]->getTargetType() == "Hind")
				{
					AIrotateAwayFromTarget(OBJ[i]->getEntity(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getRotateSpeed());
					AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
					AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					if (measureDistance(OBJ[i]->getEntity(), *OBJ[i]->getTarget()) < 70)
					{

					}
					OBJ[i]->fireMachinegun();

				}
				
				if (OBJ[i]->getType() == "AA" && OBJ[i]->getTargetType() == "Hind" || OBJ[i]->getType() == "AA" && OBJ[i]->getTargetType() == "AA")
				{
					AIrotateToTarget(OBJ[i]->getEntity(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getRotateSpeed());
					AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
					AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					if (measureDistance(OBJ[i]->getEntity(), *OBJ[i]->getTarget()) < 70)
					{

					}
					OBJ[i]->Fire();
				}

				if (OBJ[i]->getType() == "AA" && OBJ[i]->getTargetType() == "Tank")
				{
					AIrotateAwayFromTarget(OBJ[i]->getEntity(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getRotateSpeed());
					AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
					AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					if (measureDistance(OBJ[i]->getEntity(), *OBJ[i]->getTarget()) < 70)
					{

					}
					OBJ[i]->Fire();
				}


				if (OBJ[i]->getType() == "Hind" && OBJ[i]->getTargetType() == "Tank" && !OBJ[i]->getReloading())
				{
					if(measureFloats(getAngleBetween(OBJ[i]->getEntity(), *OBJ[i]->getTarget()), OBJ[i]->getEntity().getRotation()) > 150)
					{
						AIrotateToTarget(OBJ[i]->getEntity(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					}

					if (measureFloats(getAngleBetween(OBJ[i]->getEntity(), *OBJ[i]->getTarget()), OBJ[i]->getEntity().getRotation()) < 150)
					{
						AIrotateToTarget(OBJ[i]->getEntity(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					}
					if (measureFloats(getAngleBetween(OBJ[i]->getEntity(), *OBJ[i]->getTarget()), OBJ[i]->getEntity().getRotation()) < 4.5)
					{
						OBJ[i]->Fire();
					}

				}
				if (OBJ[i]->getType() == "Hind" && OBJ[i]->getTargetType() == "AA" && !OBJ[i]->getReloading()) 
				{
					if (measureFloats(getAngleBetween(OBJ[i]->getEntity(), *OBJ[i]->getTarget()), OBJ[i]->getEntity().getRotation()) > 150)
					{
						AIrotateAwayFromTarget(OBJ[i]->getEntity(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getRotateSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
						OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
						AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					}

					if (getAngleBetween(OBJ[i]->getEntity(), *OBJ[i]->getTarget()) < 4.5)
						OBJ[i]->Fire();
				}
				if(OBJ[i]->getType() == "Hind" && OBJ[i]->getTargetType() == "Hind" && !OBJ[i]->getReloading())
				{
					AIrotateToTarget(OBJ[i]->getEntity(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getRotateSpeed());
					AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					if (measureFloats(getAngleBetween(OBJ[i]->getEntity(), *OBJ[i]->getTarget()),OBJ[i]->getEntity().getRotation() < 4.5))
					{

						OBJ[i]->Fire();
					}
				}
				if (OBJ[i]->getType() == "Hind" && OBJ[i]->getReloading())
				{
					AIrotateAwayFromTarget(OBJ[i]->getEntity(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getRotateSpeed());
					AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
					OBJ[i]->moveEntity(OBJ[i]->getEntity(), "up", OBJ[i]->getSpeed());
					AIturretMove(OBJ[i]->getEntity(), OBJ[i]->getTopPart(), OBJ[i]->getRadiusofMountPoint());
				}
		}
	}
}

void AI::rotateTurretToEnemy()
{
	float distance = 1000000;
	for (int i = 0; i < OBJ.size(); i++)
	{
		for (int j = 0; j < OBJ.size(); j++)
		{
			if (!OBJ[i]->getPlayer() && OBJ[i]->getID() != OBJ[j]->getID())
			{
				if (measureDistance(OBJ[i]->getEntity(), OBJ[j]->getEntity()) < distance)
				{
					distance = measureDistance(OBJ[i]->getEntity(), OBJ[j]->getEntity());
					if (distance <= OBJ[i]->getVisibleArea())
					{
						OBJ[i]->setTarget(&OBJ[j]->getEntity());
						OBJ[i]->setTargetType(OBJ[j]->getType());
					}
					else {
						OBJ[i]->setTarget(nullptr);
						OBJ[i]->setTargetType("None");
					}
				}
			}
		}
	}
	for (int i = 0; i < OBJ.size(); i++)
		if (!OBJ[i]->getPlayer() && OBJ[i]->getTarget() != nullptr && OBJ[i]->getType() != "Hind")
		{
			AIrotateToTarget(OBJ[i]->getTopPart(), *OBJ[i]->getTarget(), OBJ[i], OBJ[i]->getTurretPointer()->getRotateSpeed());

		}
}
float AI::moduluRotation(float rotation)
{
	int temp = rotation;
	float leftover = rotation - temp;
	temp %= 360;
	float result = temp + leftover;
	return result;
}

float AI::measureFloats(float first, float second)
{
	float bigger;
	float smaller;
	if (first >= second)
	{
		bigger = first;
		smaller = second;
	}
	else { 
	bigger = second;
	smaller = first;
	}

	return bigger - smaller;
}
AI::~AI()
{
}

