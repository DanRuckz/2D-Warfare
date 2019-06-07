#include "Window_Manager.h"



Window_Manager::Window_Manager()
{
	resolution = VideoMode::getDesktopMode();
	setView();
	pipe.setMapSize(map.getBoundingRect().getSize());
	Window_action();
}




void Window_Manager::Window_action()
{
	window.create(VideoMode(resolution),"2D-Warfare", FULLSCREEN);
	Event event;
	entity = new Tank;
	Playables::setObjectsVector().push_back(entity);
	enemy = new AA;
	Playables::setObjectsVector().push_back(enemy);
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
			entity->rotateTurret();
			while (window.pollEvent(event))
			{
				if (event.type == Event::MouseMoved)
				{
					std::cout << "X coords: " << coords.x << " " << "Y coords: " << coords.y << std::endl;
					entity->rotateTurret(coords, entity->getEntity().getPosition());
				}

				if (event.type == Event::Closed)
					window.close();
				if (event.key.code == Keyboard::Escape)
					window.close();

				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left)
					{	
						timeofShot = timerofShot.getElapsedTime();
						if (timeofShot.asSeconds() > 2)
						{
							entity->Fire();
							timerofShot.restart();
						}
					}
				}
				break;
			} //END EVENT
				checkFlight();

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
			checkLimits();
			
			window.draw(map.getBoundingRect());
			for (int i = 0; i < map.getMapVec().size(); i++)
				window.draw(*map.getMapVec()[i]);

			window.setView(view);
			window.draw(enemy->getEntity());
			window.draw(enemy->getTopPart());
			window.draw(entity->getEntity());
			window.draw(entity->getTopPart());
			if (entity->getPointerToProjectile() != 0)
				window.draw(entity->getShell());
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
	if (entity->getPointerToProjectile() != NULL)
		entity->projectileFly();
	
}

void Window_Manager::limitEntity(std::string direction)
{
	if (direction == "up")
	{
		//UPPER BOUND
		if (map.getBoundingRect().getGlobalBounds().top >= entity->getEntity().getPosition().y - entity->getEntity().getTextureRect().height / 2 * entity->getEntity().getScale().y)
			entity->getEntity().setPosition(entity->getEntity().getPosition().x, entity->getEntity().getPosition().y + 15);
		//LEFT BOUND
		if (map.getBoundingRect().getGlobalBounds().left >= entity->getEntity().getPosition().x - entity->getEntity().getTextureRect().width / 2 * entity->getEntity().getScale().x - 23)
			entity->getEntity().setPosition(entity->getEntity().getPosition().x + 15, entity->getEntity().getPosition().y);

		//BOTTOM BOUND
		if (map.getBoundingRect().getGlobalBounds().height <= entity->getEntity().getPosition().y + entity->getEntity().getTextureRect().height / 2 * entity->getEntity().getScale().y - 10)
			entity->getEntity().setPosition(entity->getEntity().getPosition().x, entity->getEntity().getPosition().y - 15);

		//RIGHT BOUND
		if (map.getBoundingRect().getGlobalBounds().width <= entity->getEntity().getPosition().x + entity->getEntity().getTextureRect().width / 2 * entity->getEntity().getScale().x + 23)

			entity->getEntity().setPosition(entity->getEntity().getPosition().x - 15, entity->getEntity().getPosition().y);
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

Window_Manager::~Window_Manager()
{
}