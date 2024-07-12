#include "Application.hpp"


Application::Application(int argc, char *argv[]){
    app = new QApplication(argc, argv);
    app->setApplicationName("Primeiro app");
    
    window.resize(550, 400);
    window.setWindowTitle("Primeiro app");
    window.show();

}

Application::~Application(){
    app->exit();
    delete app;
}

void Application::run(){
    app->exec();
    
}