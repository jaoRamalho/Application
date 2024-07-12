#include "Application.hpp"

int main(int argc, char *argv[]) {
	Application* app = Application::getInstance(argc, argv);
	app->run();
};