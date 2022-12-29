#include <iostream>
#include "inits.h"
#include "Playscreen.h"
#include "Declarations.h"
sf::VideoMode resolution;
int requestedWindow;
int main(){
	requestedWindow = FIRSTSCREEN;
	Playscreen();
	//reload:
	//ptr = std::make_unique<MainScreen>();
	//ptr.reset();
	//if (!MainScreen::getExited())
	//{
	//engineptr= std::make_unique	<Window_Manager>();
	//	engineptr.reset();
	//	if (MainScreen::getExited())
	//		goto reload;
	//}
}
