#include "Login.hpp"

Login::Login() : State(500, 350){
    window.setWindowTitle("Login");
    createLoginButton();
    createRegisterButton();
    createUsernameField();
}

Login::~Login(){
    
}

void Login::createLoginButton(){
    login.setText("Login");
    login.setGeometry(WIDTH/2 - 50, HEIGHT/2, 100, 30);
    login.setParent(&window);
    login.show();
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
