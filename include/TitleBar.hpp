#pragma once
#include <QWidget>
#include <QPushButton>
#include <QPainter>

class TitleBar : public QWidget{
private:
    QPushButton exitButton;
    QPushButton minimizeButton;
    QPushButton resizeButton;
    QPushButton themaButton;
    bool changeResize;
    QWidget* window;

public:
    TitleBar(QWidget* parent, bool resize);
    ~TitleBar();

    void createButtonExit();
    void createButtonMinimize();
    void createButtonResize();
    void createButtonThema();
    void createTitleBar();
};