#include "State.hpp"

State::State(const int width, const int height) : HEIGHT(height), WIDTH(width){
    window.resize(WIDTH, HEIGHT);
}

State::~State(){

}

void State::init(){
    window.show();
}

void State::update(){

}

void State::render(){
    
}