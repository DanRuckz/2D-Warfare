#include <iostream>
#include "inits.h"
#include "Window_Manager.h"
#include "MainScreen.h"
#include "Playscreen.h"
#include "Declarations.h"
VideoMode resolution;
int main(){
	resolution = VideoMode::getDesktopMode();
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
