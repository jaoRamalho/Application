#pragma once
#include "State.hpp"
#include <unordered_map>
#include <string>

class StatesManager{
private:
    std::unordered_map<std::string ,State*> states;
    std::string currentState;
        
public:
    StatesManager();
    ~StatesManager();

    void addState(std::string name, State* state);
    void changeState(std::string name);
    State* getCurrentState();
    std::string getCurrentStateName();
};