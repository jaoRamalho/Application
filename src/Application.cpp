#include "Application.hpp"
#include "Login.hpp"

Application* Application::instance = nullptr;
Application::Application(int argc, char *argv[]) : styleSetting(new StyleSetting()){
    app = new QApplication(argc, argv);
    app->setApplicationName("Primeiro app");
    app->setStyleSheet(styleSetting->getStyle("dark"));
    createStates();
    statesManager.changeState("login");
}

Application::~Application(){
    delete app;
    delete styleSetting;
}

void Application::changeState(std::string state){
    instance->statesManager.changeState(state);
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

std::string Application::getThema(){
    return instance->styleSetting->getThema();
}

void Application::changeThema(std::string thema){
    instance->app->setStyleSheet(instance->styleSetting->getStyle(thema));
}