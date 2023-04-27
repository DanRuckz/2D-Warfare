#include <iostream>
#include "inits.h"
#include "ViewManagement.h"
#include "Static_Decl.h"
#include "globals.h"

int main(){
	auto config = Config::getInstance();
	config.setResolution(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
	ViewManagement();
}
