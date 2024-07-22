#pragma once
#include "State.hpp"
#include <QLabel>
#include <string>
#include "MenuBar.hpp"

class Home : public State{
private:
    std::string username;
    QLabel welcomeLabel;
    QPushButton settingsButton;

    void createSettingsButton();
    void createLayoutHome();
    void createCentralWidgetHome();
    void createTitleBarHome();
    void createWindowHome();
    
    MenuBar* menuBar;

public:
    Home(QWidget* parent, std::string username);

};