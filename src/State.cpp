#include "State.hpp"

State::State(QWidget* parent) : QMainWindow(parent){
    setObjectName("State");
    this->setAttribute(Qt::WA_DeleteOnClose);

}