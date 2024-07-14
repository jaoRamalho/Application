#pragma once
#include <QWidget>
#include <QLineEdit>

class State{
protected:
    const int WIDTH;
    const int HEIGHT;
    QWidget window;

public:
    State(const int width, const int height);
    virtual ~State();

    virtual void init();
    virtual void update();
    virtual void render();
};