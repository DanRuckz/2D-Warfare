#include "Window_Manager.h"



Window_Manager::Window_Manager()
{
	resolution = VideoMode::getDesktopMode();
	setView();
	Window_action();
}




void Window_Manager::Window_action()
{

	window.create(VideoMode(resolution),"2D-Warfare", WINDOW_MODE);
	Event event;
	entity = new Tank;
	enemy = new Tank;
	Clock clock_global;
	Time global;
	Clock timerofShot;
	Time timeofShot;
	while (window.isOpen())
	{
		global = clock_global.getElapsedTime();
		//change to debugModeTime or releaseModeTime depends on which mode you are
		if (global.asMilliseconds() > releaseModeTime)
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
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				entity->rotateEntity("left");
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				entity->moveEntity("down");
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				entity->rotateEntity("right");
			}
			view.setCenter(entity->getEntity().getPosition());

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
	view.setSize((float)resolution.width*1.5, (float)resolution.height*1.5);
}

void Window_Manager::checkFlight()
{
	if (entity->getPointerToProjectile() != NULL)
		entity->projectileFly();
}


Window_Manager::~Window_Manager()
{
}