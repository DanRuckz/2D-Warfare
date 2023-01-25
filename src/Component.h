#ifndef COMPONENT_H
#define COMPONENT_H
#include "inits.h"
#include "Mediator.h"

class Mediator;
class Component {
    public:
        Component(Mediator* m);
        virtual void receive(std::string message) =0;
        virtual void send(std::string message);
    protected:
        Mediator* mediator;

};
#endif