#pragma once
#include <QWidget>
#include <QLineEdit>
#include "TitleBar.hpp"

// classe para representar o states da aplicacao (telas principais com contorno eobjetos)
class State : public QWidget{
protected:
    TitleBar* titleBar;

public:
    State(QWidget* parent);
};