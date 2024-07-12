#include "Application.hpp"
#include "Login.hpp"

Application* Application::instance = nullptr;
Application::Application(int argc, char *argv[]){
    app = new QApplication(argc, argv);
    app->setApplicationName("Primeiro app");
    createStates();
    statesManager.changeState("login");
}

Application::~Application(){
    delete app;
}

Application* Application::getInstance(int argc, char *argv[]){
    if(instance == nullptr){
        instance = new Application(argc, argv);
    }
    return instance;
}

void Application::run(){
    app->exec();
}

void Application::createStates(){
    statesManager.addState("login", new Login());
}