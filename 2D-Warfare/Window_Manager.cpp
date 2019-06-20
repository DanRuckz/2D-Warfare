#include "Window_Manager.h"



Window_Manager::Window_Manager() : RespawnScreenStartPos(Vector2f(1500,1500))
{
	resolution = VideoMode::getDesktopMode();
	setView();
	Window_action();
}




void Window_Manager::Window_action()
{
	std::cout << "How many enemies do you want? " << std::endl;
	std::cin >> numOfEnemies;
	window.create(VideoMode(resolution), "2D-Warfare", WINDOW_MODE);
	Clock clock_global;
	Time global;
	Clock respawnTimer;
	Time respawnTime;
	clock_global.restart();
	makeEnemies(numOfEnemies);
	while (window.isOpen())
	{
		respawnTime = respawnTimer.getElapsedTime();
		global = clock_global.getElapsedTime();
		//change to debugModeTime or releaseModeTime depends on which mode you are
		if (global.asMilliseconds() > debugModeTime)
		{
			clock_global.restart();
			mousePos = Mouse::getPosition();
			coords = window.mapPixelToCoords(mousePos);
			
			
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.key.code == Keyboard::Escape)
					window.close();

				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left)
					{
						mouseRelease = false;
				
						if (entity != nullptr)
						{
							if (entity->getType() == "Tank")
							{	
									entity->Fire();
							}
							if (entity->getType() == "Hind")
							{
									entity->Fire();
							}

						}
					}
				}
					if (event.type == Event::MouseButtonReleased)
					{
						if (event.mouseButton.button == Mouse::Left)
							mouseRelease = true;
					}
			}
			//END EVENT
				if (!mouseRelease)
				{
					if (entity != nullptr && entity->getType() == "AA")
					{
							entity->Fire();
					}
				}
				if (entity != nullptr)
				{
					highscore.getPlayTime() = highscore.getPlayTimer().getElapsedTime();
					movement();
					checkCollisionWithObjects();
					checkFlight();
					highscore.scorePosition();
					checkHP();
				}
				
				checkLimits();
				respawn();
				ai.AImove();
				limitEntity("up");
				limitEntity("down");
				updateHP();

				if (respawnTime.asSeconds() > 5)
				{
					vecCheck();
					respawnTimer.restart();
				}

				window.draw(map.getBoundingRect());
				for (int i = 0; i < map.getMapVec().size(); i++)
					window.draw(*map.getMapVec()[i]);

				window.setView(view);
				drawProjectiles();
				correctDraw();
				
				if (respawnScreen != nullptr)
					drawRespawn();
				window.draw(highscore.getHighScore());
				window.display();
		}
	}
}

void Window_Manager::setView()
{
	view.setCenter((float)resolution.width / 2, (float)resolution.height / 2);
	view.setSize((float)resolution.width*factor, (float)resolution.height*factor);
}

void Window_Manager::checkFlight()
{
	for (int i = 0; i < OBJ.size(); i++)
	{
		for (int j = 0; j < OBJ[i]->getProjectileVector().size(); j++)
		{
			OBJ[i]->projectileFly(i);
		}
	}

}

void Window_Manager::checkHP()
{
	bool player;
	for (int i = 0; i < OBJ.size(); i++)
	{
		if (OBJ[i]->getHP() <= 0)
		{
			for (int j = 0; j < OBJ.size(); j++)
			{
				if (OBJ[i]->getLastDamaged() == OBJ[j]->getID())
				{
					OBJ[j]->increaseKillCount();
					if (OBJ[j]->getPlayer())
						highscore.updateScore();
				}
			}

			player = OBJ[i]->getPlayer();
			if (player)
			{
				entity = nullptr;
			}
			delete OBJ[i];
			OBJ[i] = nullptr;
			OBJ.erase(OBJ.begin() + i);
			}
	}
	OBJ.shrink_to_fit();
}

void Window_Manager::limitEntity(std::string direction)
{
	for (int i = 0; i < OBJ.size(); i++)
	{

		if (direction == "up")
		{
			//UPPER BOUND
			if (map.getBoundingRect().getGlobalBounds().top >= OBJ[i]->getEntity().getPosition().y - OBJ[i]->getEntity().getTextureRect().height / 2 * OBJ[i]->getEntity().getScale().y)
			{
				OBJ[i]->getEntity().move(OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180), OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180));
				OBJ[i]->getTopPart().move(OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180), OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180));
			}
			//LEFT BOUND
			if (map.getBoundingRect().getGlobalBounds().left >= OBJ[i]->getEntity().getPosition().x - OBJ[i]->getEntity().getTextureRect().width / 2 * OBJ[i]->getEntity().getScale().x - 23)
			{
				OBJ[i]->getEntity().move(-OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180), OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180));
				OBJ[i]->getTopPart().move(-OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180), OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180));

			}
			//BOTTOM BOUND
			if (map.getBoundingRect().getGlobalBounds().height <= OBJ[i]->getEntity().getPosition().y + OBJ[i]->getEntity().getTextureRect().height / 2 * OBJ[i]->getEntity().getScale().y - 10)
			{
				OBJ[i]->getEntity().move(OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180), OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180));
				OBJ[i]->getTopPart().move(OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180), OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180));
			}
			//RIGHT BOUND
			if (map.getBoundingRect().getGlobalBounds().width <= OBJ[i]->getEntity().getPosition().x + OBJ[i]->getEntity().getTextureRect().width / 2 * OBJ[i]->getEntity().getScale().x + 23)
			{
				OBJ[i]->getEntity().move(-OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180), OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180));
				OBJ[i]->getTopPart().move(-OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180), OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180));
			}
		}
		if (direction == "down")
		{
			//UPPER BOUND
			if (map.getBoundingRect().getGlobalBounds().top >= OBJ[i]->getEntity().getPosition().y - OBJ[i]->getEntity().getTextureRect().height)
			{
				OBJ[i]->getEntity().move(-OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180) / 1.5, -OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180) / 1.5);
				OBJ[i]->getTopPart().move(-OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180) / 1.5, -OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180) / 1.5);
			}
			//LEFT BOUND
			if (map.getBoundingRect().getGlobalBounds().left >= OBJ[i]->getEntity().getPosition().x - OBJ[i]->getEntity().getTextureRect().width - 23)
			{
				OBJ[i]->getEntity().move(OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180) / 1.5, -OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180) / 1.5);
				OBJ[i]->getTopPart().move(OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180) / 1.5, -OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180) / 1.5);
			}

			//BOTTOM BOUND
			if (map.getBoundingRect().getGlobalBounds().height <= OBJ[i]->getEntity().getPosition().y + OBJ[i]->getEntity().getTextureRect().height + 7)
			{
				OBJ[i]->getEntity().move(-OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180) / 1.5, -OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180) / 1.5);
				OBJ[i]->getTopPart().move(-OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180) / 1.5, -OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180) / 1.5);
			}
			//RIGHT BOUND
			if (map.getBoundingRect().getGlobalBounds().width <= OBJ[i]->getEntity().getPosition().x + OBJ[i]->getEntity().getTextureRect().width + 23)
			{
				OBJ[i]->getEntity().move(OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180) / 1.5, -OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180) / 1.5);
				OBJ[i]->getTopPart().move(OBJ[i]->getSpeed() * std::sin(OBJ[i]->getEntity().getRotation() * M_PI / 180) / 1.5, -OBJ[i]->getSpeed() * std::cos(OBJ[i]->getEntity().getRotation()* M_PI / 180) / 1.5);
			}
		}
	}
}

void Window_Manager::checkLimits()
{
	if (entity != nullptr)
	{
		Vector2f logics(Vector2f(entity->getEntity().getPosition()));

		if (entity->getEntity().getPosition().y - window.getSize().y / 2 * factor < map.getBoundingRect().getPosition().y)
		{
			logics.y = map.getBoundingRect().getPosition().y + window.getSize().y / 2 * factor;
		}
		if (entity->getEntity().getPosition().y + window.getSize().y / 2 * factor > map.getBoundingRect().getSize().y)
		{
			logics.y = map.getBoundingRect().getSize().y - window.getSize().y / 2 * factor;
		}
		if (entity->getEntity().getPosition().x - window.getSize().x / 2 * factor < map.getBoundingRect().getPosition().x)
		{
			logics.x = map.getBoundingRect().getPosition().x + window.getSize().x / 2 * factor;
		}
		if (entity->getEntity().getPosition().x + window.getSize().x / 2 * factor > map.getBoundingRect().getSize().x)
		{
			logics.x = map.getBoundingRect().getSize().x - window.getSize().x / 2 * factor;
		}

		view.setCenter(logics);
	}
}

void Window_Manager::makeEntity(std::string type)
{

	highscore.getPlayTimer().restart();
	if(type == "tank")
	entity = new Tank;
	if (type == "AA")
	entity = new AA;
	if (type == "hind")
	entity = new Hind;

	highscore.setEntityPtr(entity);
	entity->setPlayer(true);
	entity->setSelfIndex(OBJ.size());
	entity->setRandomPosition();
	OBJ.push_back(entity);
}

void Window_Manager::makeEnemies(int howmany)
{
	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist;
	int random;
	for (int i = 0; i < howmany; i++)
	{
		random = dist(gen) % 3;

		if (random == 0)
			enemy = new Tank;
		else if (random == 1)
			enemy = new AA;
		else if (random == 2)
			enemy = new Hind;

		enemy->setSelfIndex(OBJ.size());
		enemy->setRandomPosition();
		OBJ.push_back(enemy);
		enemy = nullptr;
	}
}

void Window_Manager::drawRespawn()
{
	window.draw(respawnScreen->getSprite());
	window.draw(respawnScreen->getTankSprite());
	window.draw(respawnScreen->getHindSprite());
	window.draw(respawnScreen->getAASprite());

	window.draw(respawnScreen->getTankTurretSprite());
	window.draw(respawnScreen->getAATurretSprite());
	window.draw(respawnScreen->getHindBladesSprite());
	window.draw(respawnScreen->getTitleSprite());
}

void Window_Manager::correctDraw()
{
	for (int i = 0; i < OBJ.size(); i++)
	{
		OBJ[i]->rotateTurret();
		window.draw(OBJ[i]->getEntity());
		window.draw(OBJ[i]->getTopPart());
		window.draw(OBJ[i]->getHPText());
	}
}

void Window_Manager::movement()
{

	if (event.type == Event::MouseMoved)
	{
		std::cout << "X coords: " << coords.x << " " << "Y coords: " << coords.y << std::endl;
		entity->rotateTurret(coords, entity->getEntity().getPosition());
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		entity->moveEntity("up");
		limitEntity("up");
		
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		entity->rotateEntity("left");

	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		entity->moveEntity("down");
		limitEntity("down");
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		entity->rotateEntity("right");
	}
}

void Window_Manager::drawProjectiles()
{
	for (int i = 0; i <OBJ.size(); i++)
		for(int j =0;j< OBJ[i]->getProjectileVector().size();j++)
		window.draw(OBJ[i]->getProjectileVector()[j]->getSprite());
}

void Window_Manager::respawn()
{
	if (entity == nullptr)
	{
		if (respawnScreen == nullptr)
			respawnScreen = std::make_unique<RespawnScreen>(RespawnScreenStartPos);
		view.setCenter(respawnScreen->getSprite().getPosition());
		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				if (respawnScreen->getTankSprite().getGlobalBounds().contains(coords))
				{
					type == "tank";
					respawnScreen.reset();
					makeEntity("tank");
					Playables::sortbyType();
				}
				else if (respawnScreen->getAASprite().getGlobalBounds().contains(coords))
				{
					type == "AA";
					respawnScreen.reset();
					makeEntity("AA");
					Playables::sortbyType();
				}
				else if (respawnScreen->getHindSprite().getGlobalBounds().contains(coords))
				{
					type == "hind";
					respawnScreen.reset();
					makeEntity("hind");
					Playables::sortbyType();
				}
			}
		}
	}
}

void Window_Manager::checkCollisionWithObjects()
{
	Vector2f movementVector;
	float to_radians = entity->getEntity().getRotation() * M_PI/180;
	for (int i = 0; i < OBJ.size(); i++)
	{
		for (int j = 0; j < OBJ.size(); j++)
		{
			if (OBJ[j]->getID() != OBJ[i]->getID() && Collision::PixelPerfectTest(OBJ[j]->getEntity(), OBJ[i]->getEntity()))
			{
				if (OBJ[j]->getType() != "Hind" && OBJ[i]->getType() != "Hind")
				{
					OBJ[j]->getEntity().move(-entity->getSpeed() * std::sin(to_radians), entity->getSpeed() * std::cos(to_radians));
					OBJ[j]->getTopPart().move(-entity->getSpeed() * std::sin(to_radians), entity->getSpeed() * std::cos(to_radians));
				}
			}
			if (OBJ[j]->getID() != OBJ[i]->getID() && Collision::PixelPerfectTest(OBJ[j]->getEntity(), OBJ[i]->getEntity()))
			{
				if (OBJ[j]->getType() == "Hind" && OBJ[i]->getType() == "Hind")
				{
					OBJ[i]->setHP(0);
					OBJ[j]->setHP(0);
				}
			}
		}
	}
}

void Window_Manager::vecCheck()
{
	bool respawn = false;
	for (int i = 0; i < OBJ.size(); i++)
		if (OBJ[i]->getPlayer())
			respawn = true;

	if (respawn && OBJ.size() < numOfEnemies)
		makeEnemies(1);
}

void Window_Manager::updateHP()
{
	for (int i = 0; i < OBJ.size(); i++)
	{
		OBJ[i]->updateHPText();
	}
}
Window_Manager::~Window_Manager()
{
}