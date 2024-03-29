#include "Component.h"

Component::Component(Mediator* m) : mediator(m){
}

void Component::send(std::string message){
    mediator->send(message, this);
}

void Component::setWindow(const int view){
    currentWindow = view;
}

void Component::initViews(){
    currentWindow = MENU;
}