#include "TitleBar.hpp"
#include "Application.hpp"

TitleBar::TitleBar(QWidget* parent, bool minimize,  bool resize=false) : QWidget(parent), window(parent), changeResize(resize){
    if (changeResize)
        createButtonResize();
    
    this->setObjectName("TitleBar");
    parent->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);

    createTitleBar();
    createButtonExit();
    if(minimize) { createButtonMinimize(); }
    createButtonThema();
}

TitleBar::~TitleBar(){

}

void TitleBar::createTitleBar(){
    setGeometry(0, 0, window->width(), 30);
}


void TitleBar::createButtonResize(){
    resizeButton.setText("[]");
    resizeButton.setParent(this);
    resizeButton.setGeometry(width() - 2*height(), 0, height(), height());
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
    themaButton.setGeometry(width()/2 - 5, 0, height(), height());
    window->connect(&themaButton, &QPushButton::clicked, [this](){
        (Application::getThema() == "light") ?
            Application::changeThema("dark") : Application::changeThema("light");
    });
    themaButton.show();
}

void TitleBar::createButtonExit(){
    exitButton.setText("X");
    exitButton.setParent(this);
    exitButton.setGeometry(width() - height(), 0, height(), height());
    window->connect(&exitButton, &QPushButton::clicked, [this](){
        window->close();
    });
    exitButton.show();
}

void TitleBar::createButtonMinimize(){
    minimizeButton.setText("=");
    minimizeButton.setParent(this);
    minimizeButton.setGeometry(width() - ((!changeResize)? 2*height() : 3*height()), 0, height(), height());
    window->connect(&minimizeButton, &QPushButton::clicked, [this](){
        window->showMinimized();
    });
    minimizeButton.show();
}