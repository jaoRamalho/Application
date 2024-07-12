#pragma once
#include <QWidget>
#include <QPushButton>

class State{
protected:
    QWidget window;

public:
    State();
    virtual ~State();

    virtual void init();
    virtual void update();
    virtual void render();
};