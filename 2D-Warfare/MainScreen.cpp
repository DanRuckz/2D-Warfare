#include "MainScreen.h"



MainScreen::MainScreen()
{
	resolution = VideoMode::getDesktopMode();
	baseptr = this;
	baseptr->setEntity(backgroundSprite, Vector2f(0, 0), IntRect(Vector2i(0, 0), Vector2i(1920, 1080)), "mainScreen");
	baseptr->setEntity(arrowUp, Vector2f(resolution.width/2, resolution.height/2 -120), IntRect(Vector2i(0, 0), Vector2i(256, 256)), "arrowUp");
	baseptr->setEntity(arrowDown, Vector2f(resolution.width/2, resolution.height/2 + 120), IntRect(Vector2i(0, 0), Vector2i(256, 256)), "arrowDown");
	baseptr->setEntity(Play, Vector2f(resolution.width/2 - 360, resolution.height/2 + 260), IntRect(Vector2i(0, 0), Vector2i(317, 146)), "Play");
	baseptr->setEntity(Exit, Vector2f(resolution.width/2 + 360, resolution.height/2 + 260), IntRect(Vector2i(0, 0), Vector2i(279, 146)), "Exit");
	baseptr->setEntity(Players, Vector2f(resolution.width / 2, resolution.height / 2 - 400), IntRect(Vector2i(0, 0), Vector2i(730, 115)), "players");
	baseptr->setEntity(Rect, Vector2f(resolution.width/2,resolution.height/2), IntRect(Vector2i(0, 0), Vector2i(600, 600)), "rect");
	backgroundSprite.setOrigin(0, 0);
	arrowUp.setScale(0.3, 0.3);
	arrowDown.setScale(0.3, 0.3);
	Rect.setScale(0.25, 0.25);

	font.loadFromFile("assets/ariali.ttf");
	number.setFont(font);
	number.setCharacterSize(75);
	number.setFillColor(Color::Black);
	number.setString("1");
	number.setPosition(Vector2f(resolution.width / 2 - 20, resolution.height / 2 - 45));
	//number.setString("15");
	//number.setPosition(Vector2f(resolution.width/2 - 45, resolution.height/2 - 45));
	createWindow();
}

void MainScreen::setExited(bool other)
{
	exited = other;
}

bool MainScreen::getExited()
{
	return exited;
}

int MainScreen::getNumberofPlayers()
{
	return numberofPlayers;
}

Sprite MainScreen::getMainSprite()
{
	return backgroundSprite;
}

void MainScreen::loadAndPlayMenuSound() {



	if (!sb.loadFromFile("assets/Jesper Kyd - Heroes And Generals German Theme.ogg")) {
		std::cout << "Sound Error";
		return;
	}

	menuMusic.setBuffer(sb);
	menuMusic.setVolume(30);
	menuMusic.play();

}

void MainScreen::createWindow() {

	window.create(VideoMode(resolution), "2D-Warfare", WINDOW_MODE);
	 
	Event event;
	Color color;
	color = Play.getColor();
	loadAndPlayMenuSound();
	while (window.isOpen())
	{
		mousePos = Mouse::getPosition();
		coords = window.mapPixelToCoords(mousePos);
		retrieveColors();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				exited = true;
			}


			if(event.type == Event::MouseMoved)
			{
				fadeColors(color);
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				exited = true;
				window.close();
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (Play.getGlobalBounds().contains(coords))
					{
						menuMusic.stop();
						window.close();
					}
					if (Exit.getGlobalBounds().contains(coords))
					{
						exited = true;
						window.close();
					}
					if (arrowUp.getGlobalBounds().contains(coords))
					{	
						if (numberofPlayers < 30)
						{
							numberofPlayers += 1;
							numberOfPlayers = std::to_string(numberofPlayers);
							number.setString(numberOfPlayers);
							if (numberofPlayers > 9) number.setPosition(Vector2f(resolution.width / 2 - 45, resolution.height / 2 - 45));
							else number.setPosition(Vector2f(resolution.width / 2 - 20, resolution.height / 2 - 45));
						}
					}
					if (arrowDown.getGlobalBounds().contains(coords))
					{			
						if (numberofPlayers > 1)
						{
							numberofPlayers -= 1;
							numberOfPlayers = std::to_string(numberofPlayers);
							number.setString(numberOfPlayers);
							if (numberofPlayers > 9) number.setPosition(Vector2f(resolution.width / 2 - 45, resolution.height / 2 - 45));
							else number.setPosition(Vector2f(resolution.width / 2 - 20, resolution.height / 2 - 45));
						}
						
					}
				}
			}
		} //END EVENT

		window.draw(backgroundSprite);
		window.draw(arrowUp);
		window.draw(arrowDown);
		window.draw(Play);
		window.draw(Exit);
		window.draw(Players);
		window.draw(Rect);
		window.draw(number);
		window.display();
	}
}

MainScreen::~MainScreen()
{

}

void MainScreen::fadeColors(Color& color)
{
	if (Play.getGlobalBounds().contains(coords))
	{
		Play.setColor(Color(color.r, color.g, color.b, 100));
	}
	if (Exit.getGlobalBounds().contains(coords))
	{
		Exit.setColor(Color(color.r, color.g, color.b, 100));
	}
	if (arrowUp.getGlobalBounds().contains(coords))
	{
		arrowUp.setColor(Color(color.r, color.g, color.b, 100));
	}
	if (arrowDown.getGlobalBounds().contains(coords))
	{
		arrowDown.setColor(Color(color.r, color.g, color.b, 100));
	}
}

void MainScreen::retrieveColors()
{
		if(!Play.getGlobalBounds().contains(coords))
		Play.setColor(Color(Play.getColor().r, Play.getColor().g, Play.getColor().b,255));
		if (!Exit.getGlobalBounds().contains(coords))
		Exit.setColor(Color(Exit.getColor().r, Exit.getColor().g, Exit.getColor().b, 255));
		if (!arrowUp.getGlobalBounds().contains(coords))
		arrowUp.setColor(Color(arrowUp.getColor().r, arrowUp.getColor().g, arrowUp.getColor().b, 255));
		if (!arrowDown.getGlobalBounds().contains(coords))
		arrowDown.setColor(Color(arrowDown.getColor().r, arrowDown.getColor().g, arrowDown.getColor().b, 255));
}