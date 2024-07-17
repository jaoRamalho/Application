#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <string>
#include <QString>

class Error : public QWidget{
private:
    QLabel errorLabel;
    QPushButton errorButton;

    void createErrorLabel(std::string message);
    void createErrorButton();
    void createErrorWindow();

public:
    Error(QWidget* parent, std::string message);

};