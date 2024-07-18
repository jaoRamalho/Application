#pragma once
#include <QWidget>
#include <QLineEdit>
#include "TitleBar.hpp"


class State : public QWidget{
protected:
    TitleBar* titleBar;

public:
    State(QWidget* parent);

    virtual void init();
    virtual void update();
    virtual void render();
};