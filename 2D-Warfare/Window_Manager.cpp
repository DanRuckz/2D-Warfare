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
	bool fired = false;
	while (window.isOpen())
	{
		mousePos = Mouse::getPosition();
		coords = window.mapPixelToCoords(mousePos);
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

				if (event.key.code == Mouse::Left)
				{	
					entity->Fire();
					fired = true;
				}
				break;
				
			} //END EVENT

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
		window.draw(entity->getEntity());
		window.draw(entity->getTopPart());

		if(fired)
		window.draw(entity->getShell());

		window.display();
	}

}

void Window_Manager::setView()
{
	view.setCenter((float)resolution.width / 2, (float)resolution.height / 2);
	view.setSize((float)resolution.width, (float)resolution.height);
}

void Window_Manager::checkFlight()
{
	//if (entity->getProjectilePtr()->getProjectile() != NULL)
	//	entity->getProjectilePtr()->Fly();

}


Window_Manager::~Window_Manager()
{
}