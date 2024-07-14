#include "Login.hpp"
#include "Application.hpp"
#include <iostream>

Login::Login() : State(500, 350){
    window.setWindowTitle("Login");
    createLoginButton();
    createRegisterButton();
    createUsernameField();
    createChangeThemaButton();
}

Login::~Login(){
    
}

void Login::createLoginButton(){
    login.setText("Login");
    login.setGeometry(WIDTH/2 - 50, HEIGHT/2, 100, 30);
    login.setParent(&window);
    window.connect(&login, &QPushButton::clicked, [this](){
        std::cout << "Username: " << this->usernameField.text().toStdString() << std::endl;
    });
    login.show();
}

void Login::createChangeThemaButton(){
    changeThema.setText("X");
    changeThema.setGeometry(5, 5, 15, 15);
    changeThema.setParent(&window);
    
    window.connect(&changeThema, &QPushButton::clicked, [](){
        if(Application::getThema() == "light")
            Application::changeThema("dark");
        else
            Application::changeThema("light");
    });
    
    changeThema.show();
}

void Login::createRegisterButton(){
    registerr.setText("Register");
    registerr.setGeometry(WIDTH/2 - 50, HEIGHT/2 + 50, 100, 30);
    registerr.setParent(&window);
    registerr.show();
}

void Login::createUsernameField(){
    usernameField.setParent(&window);
    usernameField.setPlaceholderText("Username");
    usernameField.setGeometry(WIDTH/2 - 100, HEIGHT/2 - 45, 200, 30); 
    usernameField.show();
}