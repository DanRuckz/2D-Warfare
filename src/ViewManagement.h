#ifndef PLAYSCREEN
#define PLAYSCREEN
#include "inits.h"
#include "globals.h"
#include "MainMenuWindow.h"
#include "GameWindow.h"
#include "WindowMediator.h"
#include <unordered_map>

class MainMenuWindow;
class GameWindow;
class ViewManagement {
    public:
        ViewManagement();

    private:
        inline void runGame();
        Mediator* mediator;
        Component* mainScreen;
        RenderWindow window;
        std::unique_ptr<MainMenuWindow> menuwindow;
        std::unique_ptr<GameWindow> gamewindow;
        std::unique_ptr<Component> contentWindow;
        std::unordered_map<int, std::unique_ptr<Component>> viewsMap;
};

#endif