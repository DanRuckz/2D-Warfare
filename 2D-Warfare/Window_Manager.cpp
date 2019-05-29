#include "Window_Manager.h"



Window_Manager::Window_Manager()
{
	resolution = VideoMode::getDesktopMode();
	makeWindow();
}


Window_Manager::~Window_Manager()
{
}

void Window_Manager::makeWindow()
{
	window.create(VideoMode(resolution),"2D-Warfare", FULLSCREEN);

	while (window.isOpen())
	{
		Vector2i mousePos = Mouse::getPosition();
		coords = window.mapPixelToCoords(mousePos);

		Event event;
		while (window.pollEvent(event))
		{
				if( Event::Closed)
				window.close();
				break;
				
				if (event.key.code == Mouse::Right)
				{

				}
				break;
			}

		window.display();
	}

}
