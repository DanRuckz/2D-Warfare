#ifndef MEDIATOR_H
#define MEDIATOR_H
#include "inits.h"
#include "Component.h"
class Component;
class Mediator{
    public:
    virtual void send(std::string message, Component* sender) =0;
    virtual void add(Component* component) = 0;
    virtual void remove(Component* component) = 0;
};
#endif