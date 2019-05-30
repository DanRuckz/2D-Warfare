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

	while (window.isOpen())
	{
		Vector2i mousePos = Mouse::getPosition();
		coords = window.mapPixelToCoords(mousePos);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseMoved)
				std::cout << "X coords: " << coords.x << " " << "Y coords: " << coords.y <<std::endl;

			if (event.type == Event::Closed)
				window.close();
			if (event.key.code == Keyboard::Escape)
				window.close();

				if (event.key.code == Mouse::Right)
				{

				}
				break;
				
			}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			view.move(0.f, -15.f);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			view.move(-15.f, 0.f);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			view.move(0.f, 15.f);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			view.move(15.f, 0.f);
		}
		
		for (int i = 0; i < map.getMapVec().size(); i++)
			window.draw(*map.getMapVec()[i]);

		window.setView(view);
		window.display();

	}

}

void Window_Manager::setView()
{
	view.setCenter(resolution.width / 2, resolution.height / 2);
	view.setSize(resolution.width, resolution.height);
}


Window_Manager::~Window_Manager()
{
}