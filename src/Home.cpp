#include "Home.hpp"
#include <iostream>


Home::Home(QWidget* parent, std::string username) : State(parent){
    this->username = username;
    createWindowHome();
    
}

void Home::createLayoutHome(){

}

void Home::createCentralWidgetHome()
{
}

void Home::createTitleBarHome(){
    
}

void Home::createWindowHome(){
    this->setGeometry(0, 0, 1280, 720);
    menuBar = new MenuBar(this);
    titleBar = TitleBar::createTitleBarCustomized(this, true, true, false, true, true, true, true); 
    this->showFullScreen();
}