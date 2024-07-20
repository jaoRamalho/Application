#pragma once
#include <QMainWindow>
#include <QLineEdit>
#include "TitleBar.hpp"

// classe para representar o states da aplicacao (telas principais com contorno eobjetos)
class State : public QMainWindow{
protected:
    TitleBar* titleBar;

public:
    State(QWidget* parent);
};