#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <string>
#include <QString>
#include <QTimer>

class Error : public QWidget{
private:
    QLabel errorLabel;
    QTimer timer;
    QPushButton exitButton;

    void createErrorLabel(std::string message);
    void createExitButton();
    void createErrorWindow();
    void createTimer();

public:
    Error(QWidget* parent, std::string message);

};