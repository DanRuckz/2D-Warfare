#include "Window_Manager.h"


Window_Manager::Window_Manager(Map& map) : map (map)
{
	resolution = VideoMode::getDesktopMode();
	makeWindow();
}




void Window_Manager::makeWindow()
{
	window.create(VideoMode(resolution),"2D-Warfare", WINDOW_MODE);

	while (window.isOpen())
	{
		Vector2i mousePos = Mouse::getPosition();
		coords = window.mapPixelToCoords(mousePos);

		Event event;
		while (window.pollEvent(event))
		{
				
				if (event.key.code == Mouse::Right)
				{

				}
				break;
			}

		for (int i = 0; i < map.getMapVec().size(); i++)
			window.draw(*map.getMapVec()[i]);
		window.display();

	}

}


Window_Manager::~Window_Manager()
{
}