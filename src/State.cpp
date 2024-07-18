#include "State.hpp"

State::State(QWidget* parent) : QWidget(parent){
    setObjectName("State");
    this->setAttribute(Qt::WA_DeleteOnClose);

}