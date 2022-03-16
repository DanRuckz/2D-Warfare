#include "Playscreen.h"



Playscreen::Playscreen(){
createwindow();
}

    inline void Playscreen::createwindow(){
	VideoMode::getDesktopMode();
	//resolution.width = 1920;
	//resolution.height = 1080;
	window.create(resolution, "2D-Warfare", FULLSCREEN);
	auto gamewindow = std::make_unique<Window_Manager>(&window);
    //auto menuwindow = std::make_unique<MainScreen>(&window);
}
