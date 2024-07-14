#pragma once
#include <QApplication>
#include "StatesManager.hpp"
#include <string>
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
};