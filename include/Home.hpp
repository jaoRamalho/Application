#pragma once
#include "State.hpp"
#include <QLabel>
#include <string>

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
    

public:
    Home(QWidget* parent, std::string username);

};