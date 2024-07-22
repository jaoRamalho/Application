#include "MenuBar.hpp"
#include "LinkManager.hpp"


MenuBar::MenuBar(QWidget* parent) : QWidget(parent) {
    setObjectName("Menu-Bar");
    
    resize(40, parent->height());
    createExitButton();
    createHomeButton();
    createJottingButton();
    createSearchButton();
    createSettingsButton();
    
    show();
}


void MenuBar::createSettingsButton(){
    LinkManager links;
    settingsButton.setIcon(QIcon(links.getLink("icon-settings-white")));
    settingsButton.setParent(this);
    settingsButton.setGeometry(0, height() - 2 * width(), width(), width());
    connect(&settingsButton, &QPushButton::clicked, [this](){

    });
    settingsButton.show();
}

void MenuBar::createHomeButton(){
    LinkManager links;
    homeButton.setIcon(QIcon(links.getLink("icon-home-white")));
    homeButton.setParent(this);
    homeButton.setGeometry(0, width(), width(), width());
    connect(&homeButton, &QPushButton::clicked, [this](){

    });
    homeButton.show();
}

void MenuBar::createExitButton(){
    LinkManager links;
    exitButton.setIcon(QIcon(links.getLink("icon-exit-white")));
    exitButton.setParent(this);
    exitButton.setGeometry(0, height() - width(), width(), width());
    connect(&exitButton, &QPushButton::clicked, [this](){
        
    });
    exitButton.show();
}

void MenuBar::createSearchButton(){
    LinkManager links;
    searchButton.setIcon(QIcon(links.getLink("icon-search-white")));
    searchButton.setParent(this);
    searchButton.setGeometry(0, 3*width(), width(), width());
    connect(&searchButton, &QPushButton::clicked, [this](){
    });
    searchButton.show();
}

void MenuBar::createJottingButton(){
    LinkManager links;
    jottingButton.setIcon(QIcon(links.getLink("icon-insignes-white")));
    jottingButton.setParent(this);
    jottingButton.setGeometry(0, 2*width(), width(), width());
    connect(&jottingButton, &QPushButton::clicked, [this](){

    });
    jottingButton.show();
}
