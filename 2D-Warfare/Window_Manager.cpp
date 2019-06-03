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

	while (window.isOpen())
	{
		mousePos = Mouse::getPosition();
		coords = window.mapPixelToCoords(mousePos);
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseMoved)
			{
				std::cout << "X coords: " << coords.x << " " << "Y coords: " << coords.y << std::endl;
				tank.getTurret().rotateTurret(coords,tank.getTank().getPosition());
			}

			if (event.type == Event::Closed)
				window.close();
			if (event.key.code == Keyboard::Escape)
				window.close();

				if (event.key.code == Mouse::Right)
				{

				}
				break;
				
			} //END EVENT

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			tank.moveEntity("up");
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			tank.rotateEntity("left");
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			tank.moveEntity("down");
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			tank.rotateEntity("right");
		}
		view.setCenter(tank.getTank().getPosition());
		
		for (int i = 0; i < map.getMapVec().size(); i++)
			window.draw(*map.getMapVec()[i]);

		window.setView(view);
		window.draw(tank.getTank());
		window.draw(tank.getTurretSprite());
		window.display();

	}

}

void Window_Manager::setView()
{
	view.setCenter((float)resolution.width / 2, (float)resolution.height / 2);
	view.setSize((float)resolution.width, (float)resolution.height);
}


Window_Manager::~Window_Manager()
{
}