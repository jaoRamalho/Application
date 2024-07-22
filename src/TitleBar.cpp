#include "TitleBar.hpp"
#include "Application.hpp"
#include <iostream>
#include <QMouseEvent>
#include <QApplication>
#include "LinkManager.hpp"

TitleBar::TitleBar(QWidget* parent) : QWidget(parent), window(parent), changeResize(false), dragging(false){
    
    this->setObjectName("TitleBar");
    //setando a flag para a janela nao ter borda
    parent->setWindowFlags(Qt::FramelessWindowHint);
    
    //setando a flag para o qwidget ser deletado ao fechar
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->createTitleBar();
}

void TitleBar::createTitleBar(){
    setGeometry(0, 0, window->width(), 40);
}


void TitleBar::mousePressEvent(QMouseEvent* event){
    if(moved && event->button() == Qt::LeftButton){
        dragging = true;
        dragPosition = event->globalPosition().toPoint() - window->frameGeometry().topLeft();
        event->accept();
    }
}

void TitleBar::mouseMoveEvent(QMouseEvent* event){
    if(moved && dragging && (window->windowState() != Qt::WindowMaximized)){
        window->move(event->globalPosition().toPoint() - dragPosition);
        event->accept();
    }
}

void TitleBar::createButtonResize(){
    LinkManager links;
    resizeButton.setIcon(QIcon(links.getLink("icon-square-white")));
    resizeButton.setParent(this);
    resizeButton.setGeometry(width() - 2*height(), 0, height(), height());
    window->connect(&resizeButton, &QPushButton::clicked, [this](){
        if (window->isFullScreen()){
            window->setGeometry(240, 60, 600, 400);
            window->show();
        } else{
            window->showFullScreen();
        }
        resized();
    });
    resizeButton.show();
}

void TitleBar::createButtonThema(){
    LinkManager links;
    themaButton.setIcon(QIcon(links.getLink("icon-thema-white")));
    themaButton.setParent(this);
    themaButton.setGeometry(width()/2 - 5, 0, height(), height());
    window->connect(&themaButton, &QPushButton::clicked, [this](){
        (Application::getThema() == "light") ?
            Application::changeThema("dark") : Application::changeThema("light");
    });
    themaButton.show();
}

void TitleBar::createButtonIcon(){
    iconButton.setObjectName("Icon-bar");
    iconButton.setParent(this);
    iconButton.setGeometry(0, 0, height(), height());
    iconButton.setIcon(QIcon("imagens/icons/moon-white.ico"));
    window->connect(&iconButton, &QPushButton::clicked, [this](){
        
    });
    iconButton.show();
}

void TitleBar::createButtonExit(){
    LinkManager links;
    exitButton.setIcon(QIcon(links.getLink("icon-x-white")));
    exitButton.setParent(this);
    exitButton.setGeometry(width() - height(), 0, height(), height());
    window->connect(&exitButton, &QPushButton::clicked, [this](){
        window->close();
    });
    exitButton.show();
}

void TitleBar::createButtonMinimize(){
    LinkManager links;
    minimizeButton.setIcon(QIcon(links.getLink("icon-minimize-white")));
    minimizeButton.setParent(this);
    minimizeButton.setGeometry(width() - ((!changeResize)? 2*height() : 3*height()), 0, height(), height());
    window->connect(&minimizeButton, &QPushButton::clicked, [this](){
        window->showMinimized();
    });
    minimizeButton.show();
}

TitleBar* TitleBar::createTitleBarCustomized(QWidget* parent, bool minimize, bool resize, bool thema, bool exit, 
                                    bool title, bool icon, bool moved)
{
    TitleBar* titleBar = new TitleBar(parent);
    titleBar->changeResize = resize;
    titleBar->moved = moved;
    if (thema) { titleBar->createButtonThema(); }
    if (exit) { titleBar->createButtonExit(); }
    if(minimize) { titleBar->createButtonMinimize(); }
    if(resize) { titleBar->createButtonResize(); }
    if (icon) { titleBar->createButtonIcon(); }
    return titleBar;
}

void TitleBar::resized(){
    createTitleBar();
    
    themaButton.setGeometry(width()/2 - 5, 0, height(), height());
    minimizeButton.setGeometry(width() - ((!changeResize)? 2*height() : 3*height()), 0, height(), height());
    exitButton.setGeometry(width() - height(), 0, height(), height());
    resizeButton.setGeometry(width() - 2*height(), 0, height(), height());
    iconButton.setGeometry(0, 0, height(), height());
}
