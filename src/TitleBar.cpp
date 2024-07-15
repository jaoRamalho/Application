#include "TitleBar.hpp"
#include "Application.hpp"

TitleBar::TitleBar(QWidget* window,  bool resize=false) : window(window), resize(resize){
    window = window;
    if (resize)
        createButtonResize();

    window->setWindowFlags(Qt::FramelessWindowHint);
    createButtonExit();
    createButtonMinimize();
    createButtonThema();
}

TitleBar::~TitleBar(){

}

void TitleBar::createButtonResize(){
    resizeButton.setText("[]");
    resizeButton.setGeometry(window->width() - 50, 0, 25, 25);
    resizeButton.setParent(window);
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
    themaButton.setGeometry(window->width() -  ((!resize)? 75 : 90), 0, 25, 25);
    themaButton.setParent(window);
    window->connect(&themaButton, &QPushButton::clicked, [this](){
        (Application::getThema() == "light") ?
            Application::changeThema("dark") : Application::changeThema("light");
    });
    themaButton.show();
}

void TitleBar::createButtonExit(){
    exitButton.setText("X");
    exitButton.setGeometry(window->width() - 25, 0, 25, 25);
    exitButton.setParent(window);
    window->connect(&exitButton, &QPushButton::clicked, [this](){
        window->close();
    });
    exitButton.show();
}

void TitleBar::createButtonMinimize(){
    minimizeButton.setText("=");
    minimizeButton.setGeometry(window->width() - ((!resize)? 50 : 75), 0, 25, 25);
    minimizeButton.setParent(window);
    window->connect(&minimizeButton, &QPushButton::clicked, [this](){
        window->showMinimized();
    });
    minimizeButton.show();
}