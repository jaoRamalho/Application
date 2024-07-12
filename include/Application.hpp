#pragma once
#include <QApplication>
#include "State.hpp"
#include "StatesManager.hpp"
#include <string>


// Aplicativo -> classe singlenton que gerencia os estados e eventos do jogo
class Application{
private:
    static Application* instance;
    QApplication* app;
    Application(int argc, char *argv[]);

    StatesManager statesManager;
    
public:
    ~Application();

    static Application* getInstance(int argc, char *argv[]);
    void run();
    void createStates();
};