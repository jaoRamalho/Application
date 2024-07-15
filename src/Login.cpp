#include "Login.hpp"
#include "Application.hpp"
#include <iostream>

Login::Login() : State(500, 350){
    window.setWindowTitle("Login");
    
    createLoginButton();
    createRegisterButton();
    createUsernameField();
    createPasswordField();
}
 
Login::~Login(){
    
}

void Login::createPasswordField(){
    passwordField.setParent(&window);
    passwordField.setPlaceholderText("Password");
    passwordField.setEchoMode(QLineEdit::Password);
    passwordField.setGeometry(WIDTH/2 - 100, HEIGHT/2 - 45, 200, 30); 
    passwordField.show();
}

void Login::createLoginButton(){
    loginButton.setText("Login");
    loginButton.setGeometry(WIDTH/2 - 50, HEIGHT/2, 100, 30);
    loginButton.setParent(&window);
    window.connect(&loginButton, &QPushButton::clicked, [this](){
        std::cout << "Username: " << this->usernameField.text().toStdString() << std::endl;
    });
    loginButton.show();
}

void Login::createRegisterButton(){
    registerButton.setText("Register");
    registerButton.setGeometry(WIDTH/2 - 50, HEIGHT/2 + 50, 100, 30);
    registerButton.setParent(&window);
    registerButton.show();
}

void Login::createUsernameField(){
    usernameField.setParent(&window);
    usernameField.setPlaceholderText("Username");
    usernameField.setGeometry(WIDTH/2 - 100, HEIGHT/2 - 90, 200, 30); 
    usernameField.show();
}