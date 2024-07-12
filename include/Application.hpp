#pragma once
#include <QApplication>
#include <QWidget>

class Application{
private:
    QApplication* app;
    QWidget window;

public:
    Application(int argc, char *argv[]);
    ~Application();
    void run();
};