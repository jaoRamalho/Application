#pragma once 
#include "State.hpp"
#include <QPushButton>


class Login : public State{
private:
    QPushButton login;
    QPushButton registerr;
    QLineEdit usernameField;

public:
    Login();
    ~Login();

    void createLoginButton();
    void createRegisterButton();
    void createUsernameField();
};