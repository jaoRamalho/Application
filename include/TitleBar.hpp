#pragma once
#include <QWidget>
#include <QPushButton>
#include <QResizeEvent>

// classe para representar a barra de titulo de states
class TitleBar : public QWidget{
private:
    QPushButton exitButton;
    QPushButton minimizeButton;
    QPushButton resizeButton;
    QPushButton themaButton;
    QPushButton iconButton;
    
    bool changeResize;
    QWidget* window;


    TitleBar(QWidget* parent);

    void createButtonExit();
    void createButtonMinimize();
    void createButtonResize();
    void createButtonThema();
    void createButtonIcon();
    void createTitleBar();


public:
    static TitleBar* createTitleBarCustomized(QWidget* parent, bool minimize, bool resize, bool thema, bool exit, bool title, bool icon);

    void resized();
};