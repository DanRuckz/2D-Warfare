#include "MenuScreen.h"



MenuScreen::MenuScreen()
{
	resolution = VideoMode(1280, 720);
	texture.loadFromFile("assets/2D-Warfare_background.png");
	createBackground();
	createWindow();
}



void MenuScreen::createBackground(){
	
	background.setTexture(texture);
	background.setPosition(0, 0);
}

void MenuScreen::loadAndPlayMenuSound() {

	

	if (!sb.loadFromFile("assets/Jesper Kyd - Heroes And Generals German Theme.ogg")) {
		std::cout << "Sound Error";
		return;
	}

	menuMusic.setBuffer(sb);
	menuMusic.setVolume(30);
	menuMusic.play();

}

void MenuScreen::createWindow(){

	window.create(VideoMode(resolution), "2D-Warfare", WINDOW_MODE);
	Vector2i mousePos = Mouse::getPosition();
	coords = window.mapPixelToCoords(mousePos);
	Event event;
	loadAndPlayMenuSound();
	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseMoved)
				std::cout << "X coords: " << coords.x << " " << "Y coords: " << coords.y << std::endl;

			if (event.type == Event::Closed)
				window.close();
			if (event.key.code == Keyboard::Escape)
				window.close();


		} //END EVENT

		window.draw(background);
		window.display();
	}
}



MenuScreen::~MenuScreen()
{

}
