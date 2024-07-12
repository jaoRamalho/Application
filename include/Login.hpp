#pragma once 
#include "State.hpp"

class Login : public State{
private:
    QPushButton login;
    QPushButton registerr;

public:
    Login();
    ~Login();

    void init();
};