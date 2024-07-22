#pragma once 
#include "State.hpp"
#include <QPushButton>

class Login : public State{
private:
    QPushButton loginButton;
    QPushButton registerButton;
    
    QLineEdit usernameField;
    QLineEdit passwordField;

    
    void createLoginButton();
    void createRegisterButton();
    void createUsernameField();
    void createPasswordField();

public:
    Login();
    ~Login();
};