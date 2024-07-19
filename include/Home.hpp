#pragma once
#include "State.hpp"
#include <QLabel>
#include <string>

class Home : public State{
private:
    std::string username;
    QLabel welcomeLabel;
    QPushButton settingsButton;

    void createWelcomeLabel();
    void createSettingsButton();
    void createWindowHome();

public:
    Home(QWidget* parent, std::string username);

};