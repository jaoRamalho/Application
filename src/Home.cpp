#include "Home.hpp"
#include <iostream>
#include "NewsAPI.hpp"


Home::Home(QWidget* parent, std::string username) : State(parent){
    this->username = username;
    createWindowHome();


  //nlohmann::json news = NewsAPI::getNews("br", {"business", "technology", "Bitcoin", "Apple"});
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