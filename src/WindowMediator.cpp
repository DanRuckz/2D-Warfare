#include "WindowMediator.h"

void WindowMediator::send(std::string message, Component* sender){
    for (auto c : components) {
        if(c != sender){
            c->receive(message);
        }
    }
}

void WindowMediator::add(Component* component){
    components.push_back(component);
}

void WindowMediator::remove(Component* component){
    for (int i =0 ; i< components.size(); i++){
        if(components.at(i) == component){
            components.erase(components.begin() + i);
        }
    }
}
