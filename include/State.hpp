#pragma once
#include <QWidget>
#include <QLineEdit>
#include "TitleBar.hpp"


class State : public QWidget{
protected:
    TitleBar* titleBar;

public:
    State(QWidget* parent, const int WIDTH, const int HEIGHT);
    virtual ~State();

    virtual void init();
    virtual void update();
    virtual void render();
};