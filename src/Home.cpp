#include "Home.hpp"
#include <iostream>

Home::Home(QWidget* parent, std::string username) : State(parent){
    this->username = username;
    createWindowHome();

}

void Home::createWelcomeLabel(){

}

void Home::createSettingsButton(){
    settingsButton.setText("-");
    settingsButton.setParent(this);
    settingsButton.setGeometry(0, 30, 40, 40);
    connect(&settingsButton, &QPushButton::clicked, [this](){
        
    });
    settingsButton.show();
}
    
void Home::createWindowHome(){
    this->setGeometry(0, 0, 1280, 720);
    createWelcomeLabel();
    createSettingsButton();
    titleBar = TitleBar::createTitleBarCustomized(this, true, true, true, true, true, true); 
    this->showFullScreen();
}