#include "Application.hpp"
#include "Login.hpp"
#include "DataBase.hpp"

Application* Application::instance = nullptr;
Application::Application(int argc, char *argv[]) : styleSetting(new StyleSetting()){
    app = new QApplication(argc, argv);
    app->setApplicationName("Primeiro app");
    app->setStyleSheet(styleSetting->getStyle("dark"));
    DataBase* d = DataBase::getInstance();
    createStates();
  
}

Application::~Application(){
    delete app;
    delete styleSetting;
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
    Login* login = new Login();
}

std::string Application::getThema(){
    return instance->styleSetting->getThema();
}

void Application::changeThema(std::string thema){
    instance->app->setStyleSheet(instance->styleSetting->getStyle(thema));
}