#include "StatesManager.hpp"

StatesManager::StatesManager() : currentState("none"){

}

StatesManager::~StatesManager(){
    for(auto it : states){
        delete it.second;
    }
    states.clear();
}

void StatesManager::addState(std::string name, State* state){
    states[name] = state;
}

void StatesManager::changeState(std::string name){
    currentState = name;
}

State* StatesManager::getCurrentState(){
    return states[currentState];
}

std::string StatesManager::getCurrentStateName(){
    return currentState;
}