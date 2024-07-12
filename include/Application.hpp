#pragma once
#include <QApplication>
#include "State.hpp"
#include <unordered_map>
#include <string>

class Application{
private:
    QApplication* app;
    std::unordered_map<std::string, State*> states;

public:
    Application(int argc, char *argv[]);
    ~Application();

    void run();
    void createStates();
    void eventStates(std::string state);
    void addState(std::string name, State* state);
};