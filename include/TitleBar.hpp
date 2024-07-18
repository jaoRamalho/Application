#pragma once
#include <QWidget>
#include <QPushButton>


// classe para representar a barra de titulo de states
class TitleBar : public QWidget{
private:
    QPushButton exitButton;
    QPushButton minimizeButton;
    QPushButton resizeButton;
    QPushButton themaButton;
    
    bool changeResize;
    QWidget* window;


    TitleBar(QWidget* parent);

    void createButtonExit();
    void createButtonMinimize();
    void createButtonResize();
    void createButtonThema();
    void createTitleBar();


public:
    static TitleBar* createTitleBarCustomized(QWidget* parent, bool minimize, bool resize, bool thema, bool exit, bool title, bool icon);
};