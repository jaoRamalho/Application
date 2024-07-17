#include "State.hpp"

State::State(QWidget* parent, const int WIDTH, const int HEIGHT) : QWidget(parent){
    resize(WIDTH, HEIGHT);
    titleBar = new TitleBar(this, false);
}

State::~State(){
}

void State::init(){
    show();
}

void State::update(){

}

void State::render(){
    
}