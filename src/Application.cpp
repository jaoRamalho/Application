#include "Application.hpp"


Application::Application(int argc, char *argv[]){
    app = new QApplication(argc, argv);
    app->setApplicationName("Primeiro app");
}

Application::~Application(){
    app->exit();
    delete app;
}

void Application::run(){
    app->exec();
    
}

void Application::createStates(){

}

void Application::eventStates(std::string state){

}

void Application::addState(std::string name, State* state){

}
