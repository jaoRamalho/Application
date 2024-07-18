#include "Register.hpp"
#include "DataBase.hpp"
#include "Error.hpp"

Register::Register(QWidget* parent = nullptr) : State(parent){
    setWindowTitle("Register");

    float w = parent->width();
    float h = parent->height();
    setGeometry(w*0.1, 35, 0.8*w, 0.8*h); // 20% da tela do pai (login)
    titleBar = TitleBar::createTitleBarCustomized(this, false, false, false, true, false, false);

    createNameField();
    createUsernameField();
    createPasswordField();
    createConfirmPasswordField();
    createRegisterButton();
    show();
}

void Register::createNameField(){
    nameField.setParent(this);
    nameField.setPlaceholderText("Name");
    nameField.setGeometry(width()/2 - 100, height()/2 - 80, 200, 30); 
    nameField.show();
}

void Register::createUsernameField(){
    usernameField.setParent(this);
    usernameField.setPlaceholderText("Username");
    usernameField.setGeometry(width()/2 - 100, height()/2 - 40, 200, 30); 
    usernameField.show();
}

void Register::createPasswordField(){
    passwordField.setParent(this);
    passwordField.setPlaceholderText("Password");
    passwordField.setEchoMode(QLineEdit::Password);
    passwordField.setGeometry(width()/2 - 100, height()/2, 200, 30); 
    passwordField.show();
}

void Register::createConfirmPasswordField(){
    confirmPasswordField.setParent(this);
    confirmPasswordField.setPlaceholderText("Confirm Password");
    confirmPasswordField.setEchoMode(QLineEdit::Password);
    confirmPasswordField.setGeometry(width()/2 - 100, height()/2 + 40, 200, 30); 
    confirmPasswordField.show();
}

void Register::createRegisterButton(){
    registerButton.setText("Register");
    registerButton.setParent(this);
    registerButton.setGeometry(width()/2 - 50, height()/2 + 80, 100, 30);
    
    connect(&registerButton, &QPushButton::clicked, [this](){
        std::string name = nameField.text().toStdString();
        std::string username = usernameField.text().toStdString();
        std::string password = passwordField.text().toStdString();
        std::string confirmPassword = confirmPasswordField.text().toStdString();
        
        RegisterError error = DataBase::newUser(name, username, password, confirmPassword);
        std::string message = DataBase::messageError(error);
        Error* messageWindow = new Error(this, message);
    });


    registerButton.show();
}
