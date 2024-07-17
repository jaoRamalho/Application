#include "Login.hpp"
#include "Application.hpp"
#include <iostream>
#include "DataBase.hpp"
#include "Error.hpp"

Login::Login() : State(nullptr ,500, 350){
    setWindowTitle("Login");
    
    createLoginButton();
    createRegisterButton();
    createUsernameField();
    createPasswordField();
}
 
Login::~Login(){
    
}

void Login::createPasswordField(){
    passwordField.setParent(this);
    passwordField.setPlaceholderText("Password");
    passwordField.setEchoMode(QLineEdit::Password);
    passwordField.setGeometry(width()/2 - 100, height()/2 - 45, 200, 30); 
    passwordField.show();
}

void Login::createLoginButton(){
    loginButton.setText("Login");
    loginButton.setParent(this);
    loginButton.setGeometry(width()/2 - 50, height()/2, 100, 30);
    connect(&loginButton, &QPushButton::clicked, [this](){
        std::string username = usernameField.text().toStdString();
        std::string password = passwordField.text().toStdString();
        if (DataBase::checkLoginDataBase(username, password)){
            std::cerr << "Logado" << std::endl;
        }
        else{
            Error* erro = new Error(this, "Login ou senha incorretos");
        }
    });
    loginButton.show();
}

void Login::createRegisterButton(){
    registerButton.setText("Register");
    registerButton.setParent(this);
    registerButton.setGeometry(width()/2 - 50, height()/2 + 50, 100, 30);
    connect(&registerButton, &QPushButton::clicked, [this](){
        std::string username = usernameField.text().toStdString();
        std::string password = passwordField.text().toStdString();
        if (DataBase::newUser(username, password)){
            Error* erro = new Error(this, "Usuario registrado");
        }
        else{
            Error* erro = new Error(this, "Usuario ja registrado");
        }
    });
    registerButton.show();
}

void Login::createUsernameField(){
    usernameField.setParent(this);
    usernameField.setPlaceholderText("Username");
    usernameField.setGeometry(width()/2 - 100, height()/2 - 90, 200, 30); 
    usernameField.show();
}