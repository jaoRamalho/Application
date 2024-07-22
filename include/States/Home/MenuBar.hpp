#pragma once
#include <QWidget>
#include <QPushButton>

class MenuBar : public QWidget{
private:
    QPushButton settingsButton;
    QPushButton exitButton;
    QPushButton homeButton;
    QPushButton searchButton;
    QPushButton jottingButton;


    void createSettingsButton();
    void createHomeButton();
    void createExitButton();
    void createSearchButton();
    void createJottingButton();
    
public:
    MenuBar(QWidget* parent);

};