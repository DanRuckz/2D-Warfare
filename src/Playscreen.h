#ifndef PLAYSCREEN
#define PLAYSCREEN
#include "inits.h"
#include "globals.h"
#include "MainScreen.h"
#include "Window_Manager.h"
#include "WindowMediator.h"

class MainScreen;
class Window_Manager;
class Playscreen {
    public:
        Playscreen();
        sf::VideoMode getResolution();

    private:
        inline void runGame();
        Mediator* mediator;
        Component* mainScreen;
        RenderWindow window;
        std::unique_ptr<MainScreen> menuwindow;
        std::unique_ptr<Window_Manager> gamewindow;
        sf::VideoMode resolution;
};

#endif