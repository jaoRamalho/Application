#include "Login.hpp"
#include <iostream>
#include "DataBase.hpp"
#include "Error.hpp"
#include "Register.hpp"
#include "Home.hpp"


Login::Login() : State(nullptr){
    resize(400, 300);
    titleBar = TitleBar::createTitleBarCustomized(this, true, false, true, true, false, true);
    
    createLoginButton();
    createRegisterButton();
    createUsernameField();
    createPasswordField();
    show();
}
 
Login::~Login(){
    
}

void Login::createPasswordField(){
    passwordField.setParent(this);
    passwordField.setPlaceholderText("Password");
    passwordField.setEchoMode(QLineEdit::Password);
    passwordField.setGeometry(width()/2 - 100, height()/2 - 15, 200, 30); 
    passwordField.show();
}

void Login::createLoginButton(){
    loginButton.setText("Login");
    loginButton.setParent(this);
    loginButton.setGeometry(width()/2 - 50, height()/2 + 35, 100, 30);
    connect(&loginButton, &QPushButton::clicked, [this](){
        std::string username = usernameField.text().toStdString();
        std::string password = passwordField.text().toStdString();
        RegisterError error = DataBase::checkLoginDataBase(username, password);
        std::string message = DataBase::messageError(error);
        
        if (error == RegisterError::SUCCESS){
            Home* home = new Home(nullptr, username);
            this->close();
        }
        else{
            Error* messageWindow = new Error(this, message);
        }
    });
    loginButton.show();
}

void Login::createRegisterButton(){
    registerButton.setText("Register");
    registerButton.setParent(this);
    registerButton.setGeometry(width()/2 - 50, height()/2 + 80, 100, 30);
    connect(&registerButton, &QPushButton::clicked, [this](){
        Register* registerWindow = new Register(this);
    });
    registerButton.show();
}

void Login::createUsernameField(){
    usernameField.setParent(this);
    usernameField.setPlaceholderText("Username");
    usernameField.setGeometry(width()/2 - 100, height()/2 - 60, 200, 30); 
    usernameField.show();
}