#pragma once
#include <QWidget>
#include <QPushButton>
#include <QPainter>

class TitleBar{
private:
    QPushButton exitButton;
    QPushButton minimizeButton;
    QPushButton resizeButton;
    QPushButton themaButton;
    bool resize;
    QWidget* window;

public:
    TitleBar(QWidget* window, bool resize);
    ~TitleBar();

    void createButtonExit();
    void createButtonMinimize();
    void createButtonResize();
    void createButtonThema();
};