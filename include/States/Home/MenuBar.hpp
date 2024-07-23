#pragma once
#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
class MenuBar : public QWidget{
private:
    QPushButton settingsButton;
    QPushButton exitButton;
    QPushButton homeButton;
    QPushButton searchButton;
    QPushButton jottingButton;

    QButtonGroup* buttonGroup;


    void createSettingsButton();
    void createHomeButton();
    void createExitButton();
    void createSearchButton();
    void createJottingButton();
    void createButtonGroup();
    
public:
    MenuBar(QWidget* parent);

};