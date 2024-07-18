#pragma once
#include "State.hpp"


class Home : public State{
private:


public:
    Home(QWidget* parent, std::string username) : State(parent){}

};