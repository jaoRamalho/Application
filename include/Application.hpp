#pragma once

#include <QApplication>
#include <string>

#include "StatesManager.hpp"
#include "StyleSetting.hpp"

// Aplicativo -> classe singlenton que gerencia os estados e eventos do jogo
class Application{
private:
    static Application* instance;
    QApplication* app;
    StyleSetting* styleSetting;
    Application(int argc, char *argv[]);

    StatesManager statesManager;
    
public:
    ~Application();

    static Application* getInstance(int argc, char *argv[]);
    void run();
    void createStates();
    static void changeThema(std::string thema);
    static void changeState(std::string state);
    static std::string getThema();
};