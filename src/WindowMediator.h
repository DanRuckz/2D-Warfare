#ifndef WINDOWMEDIATOR_H
#define WINDOWMEDIATOR_H
#include "inits.h"
#include "Mediator.h"
#include "Component.h"

class WindowMediator : public Mediator{
    public:

        void send(std::string message, Component* sender);
        void add(Component* component);
        void remove(Component* component);
        void setWindowState(int window);
        int getWindowState();
    private:
        std::vector<Component*> components;
};
#endif