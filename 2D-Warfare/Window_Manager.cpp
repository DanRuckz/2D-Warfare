#include "Window_Manager.h"



Window_Manager::Window_Manager()
{
	resolution = VideoMode::getDesktopMode();
	setView();
	Window_action();
}




void Window_Manager::Window_action()
{
	window.create(VideoMode(resolution), "2D-Warfare", WINDOW_MODE);
	Playables::sortbyType();
	Clock clock_global;
	Time global;
	Clock timerofShot;
	Time timeofShot;
	while (window.isOpen())
	{
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
								timeofShot = timerofShot.getElapsedTime();
								if (timeofShot.asSeconds() > 2)
								{
									entity->Fire();
									timerofShot.restart();
								}
							}
							if (entity->getType() == "Hind")
							{
								if (entity->getShotsFired() < 5)
								{
									entity->Fire();
								}
								if (entity->getShotsFired() == 4)
								{
									timerofShot.restart();
								}
								timeofShot = timerofShot.getElapsedTime();
								if (entity->getShotsFired() >= 5 && timeofShot.asSeconds() > 4)
								{
									entity->nullifyShotsFired();
								}
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
						timeofShot = timerofShot.getElapsedTime();
						if (timeofShot.asSeconds() > 0.25)
						{
							entity->Fire();
							timerofShot.restart();
						}
					}
				}
				if (entity != nullptr)
				{
					movement();
					checkFlight();
					checkHP();
				}
				
				if(entity != nullptr)
				checkLimits();

				if (entity == nullptr && respawnScreen == nullptr)
				{
						respawnScreen = std::make_unique<RespawnScreen>(playerLastPosition);
						view.setCenter(respawnScreen->getSprite().getPosition());
						if (respawnScreen->getTankSprite().getGlobalBounds().contains(coords))
						{
							type == "tank";
							respawnScreen.reset();
							return;
						}
						if (respawnScreen->getAASprite().getGlobalBounds().contains(coords))
						{
							type == "AA";
							respawnScreen.reset();
							return;
						}
						if (respawnScreen->getHindSprite().getGlobalBounds().contains(coords))
						{
							type == "hind";
							respawnScreen.reset();
							return;
						}
				}
				makeEnemies(20);
				window.draw(map.getBoundingRect());
				for (int i = 0; i < map.getMapVec().size(); i++)
					window.draw(*map.getMapVec()[i]);

				window.setView(view);
				drawProjectiles();
				correctDraw();
				
				if (respawnScreen != nullptr)
					drawRespawn();
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
	for (int i = 0; i < Playables::getObjectsVector().size(); i++)
	{
		for (int j = 0; j < Playables::getObjectsVector()[i]->getProjectileVector().size(); j++)
		{
			Playables::getObjectsVector()[i]->projectileFly(i);
		}
	}

}

void Window_Manager::checkHP()
{
	bool player;
	for (int i = 0; i < Playables::getObjectsVector().size(); i++)
	{
		if (Playables::getObjectsVector()[i]->getHP() <= 0)
		{
			player = Playables::getObjectsVector()[i]->getPlayer();
			if (player)
			{
				playerLastPosition = entity->getEntity().getPosition();
				entity = nullptr;
			}
			delete Playables::getObjectsVector()[i];
			Playables::getObjectsVector()[i] = nullptr;
			Playables::getObjectsVector().erase(Playables::getObjectsVector().begin() + i);
			}
	}
	Playables::getObjectsVector().shrink_to_fit();
}

void Window_Manager::limitEntity(std::string direction)
{
	if (direction == "up")
	{
		//UPPER BOUND
		if (map.getBoundingRect().getGlobalBounds().top >= entity->getEntity().getPosition().y - entity->getEntity().getTextureRect().height / 2 * entity->getEntity().getScale().y)
			entity->getEntity().setPosition(entity->getEntity().getPosition().x, entity->getEntity().getPosition().y + entity->getSpeed());
		//LEFT BOUND
		if (map.getBoundingRect().getGlobalBounds().left >= entity->getEntity().getPosition().x - entity->getEntity().getTextureRect().width / 2 * entity->getEntity().getScale().x - 23)
			entity->getEntity().setPosition(entity->getEntity().getPosition().x + entity->getSpeed(), entity->getEntity().getPosition().y);

		//BOTTOM BOUND
		if (map.getBoundingRect().getGlobalBounds().height <= entity->getEntity().getPosition().y + entity->getEntity().getTextureRect().height / 2 * entity->getEntity().getScale().y - 10)
			entity->getEntity().setPosition(entity->getEntity().getPosition().x, entity->getEntity().getPosition().y - entity->getSpeed());

		//RIGHT BOUND
		if (map.getBoundingRect().getGlobalBounds().width <= entity->getEntity().getPosition().x + entity->getEntity().getTextureRect().width / 2 * entity->getEntity().getScale().x + 23)

			entity->getEntity().setPosition(entity->getEntity().getPosition().x - entity->getSpeed(), entity->getEntity().getPosition().y);
	}
		if (direction == "down")
	{
			//UPPER BOUND
			if (map.getBoundingRect().getGlobalBounds().top >= entity->getEntity().getPosition().y - entity->getEntity().getTextureRect().height)
				entity->getEntity().setPosition(entity->getEntity().getPosition().x, entity->getEntity().getPosition().y + 15);
			//LEFT BOUND
			if (map.getBoundingRect().getGlobalBounds().left >= entity->getEntity().getPosition().x - entity->getEntity().getTextureRect().width - 23)
				entity->getEntity().setPosition(entity->getEntity().getPosition().x + 15, entity->getEntity().getPosition().y);

			//BOTTOM BOUND
			if (map.getBoundingRect().getGlobalBounds().height <= entity->getEntity().getPosition().y + entity->getEntity().getTextureRect().height + 7)
				entity->getEntity().setPosition(entity->getEntity().getPosition().x, entity->getEntity().getPosition().y - 15);

			//RIGHT BOUND
			if (map.getBoundingRect().getGlobalBounds().width <= entity->getEntity().getPosition().x + entity->getEntity().getTextureRect().width + 23)

				entity->getEntity().setPosition(entity->getEntity().getPosition().x - 15, entity->getEntity().getPosition().y);
	}
}

void Window_Manager::checkLimits()
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

void Window_Manager::makeEntity(std::string type)
{
	if(type == "tank")
	entity = new Tank;

	entity->setPlayer(true);
	entity->setSelfIndex(Playables::getObjectsVector().size());
	entity->setRandomPosition();
	Playables::getObjectsVector().push_back(entity);
}

void Window_Manager::makeEnemies(int howmany)
{
	for (int i = 0; i < howmany; i++)
	{
		enemy = new AA;
		enemy->setSelfIndex(Playables::getObjectsVector().size());
		enemy->setRandomPosition();
		Playables::getObjectsVector().push_back(enemy);
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
	for (int i = 0; i < Playables::getObjectsVector().size(); i++)
	{
		Playables::getObjectsVector()[i]->rotateTurret();
		window.draw(Playables::getObjectsVector()[i]->getEntity());
		window.draw(Playables::getObjectsVector()[i]->getTopPart());
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
	for (int i = 0; i <Playables::getObjectsVector().size(); i++)
		for(int j =0;j< Playables::getObjectsVector()[i]->getProjectileVector().size();j++)
		window.draw(Playables::getObjectsVector()[i]->getProjectileVector()[j]->getSprite());
}

Window_Manager::~Window_Manager()
{
}