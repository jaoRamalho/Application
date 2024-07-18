#pragma once
#include "State.hpp"
#include <QLineEdit>
#include <QPushButton>


class Register : public State{
private:
    QLineEdit nameField;
    QLineEdit usernameField;
    QLineEdit passwordField;
    QLineEdit confirmPasswordField;
    QPushButton registerButton;

public:
    Register(QWidget* parent);

    void createNameField();
    void createUsernameField();
    void createPasswordField();
    void createConfirmPasswordField();
    void createRegisterButton();
};