#include "TitleBar.hpp"
#include "Application.hpp"

TitleBar::TitleBar(QWidget* parent,  bool resize=false) : QWidget(parent), window(parent), changeResize(resize){
    if (changeResize)
        createButtonResize();
    
    this->setObjectName("TitleBar");
    parent->setWindowFlags(Qt::FramelessWindowHint);
    createTitleBar();
    createButtonExit();
    createButtonMinimize();
    createButtonThema();
}

TitleBar::~TitleBar(){

}

void TitleBar::createTitleBar(){
    setGeometry(0, 0, window->width(), 25);
}


void TitleBar::createButtonResize(){
    resizeButton.setText("[]");
    resizeButton.setParent(this);
    resizeButton.setGeometry(width() - 50, 0, 25, 25);
    window->connect(&resizeButton, &QPushButton::clicked, [this](){
        if (window->isMaximized())
            window->showNormal();
        else
            window->showMaximized();
    });
    resizeButton.show();
}

void TitleBar::createButtonThema(){
    themaButton.setText("T");
    themaButton.setParent(this);
    themaButton.setGeometry(width()/2 - 12.5, 0, 25, 25);
    window->connect(&themaButton, &QPushButton::clicked, [this](){
        (Application::getThema() == "light") ?
            Application::changeThema("dark") : Application::changeThema("light");
    });
    themaButton.show();
}

void TitleBar::createButtonExit(){
    exitButton.setText("X");
    exitButton.setParent(this);
    exitButton.setGeometry(width() - 25, 0, 25, 25);
    window->connect(&exitButton, &QPushButton::clicked, [this](){
        window->close();
    });
    exitButton.show();
}

void TitleBar::createButtonMinimize(){
    minimizeButton.setText("=");
    minimizeButton.setParent(this);
    minimizeButton.setGeometry(width() - ((!changeResize)? 50 : 75), 0, 25, 25);
    window->connect(&minimizeButton, &QPushButton::clicked, [this](){
        window->showMinimized();
    });
    minimizeButton.show();
}