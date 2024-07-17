#include "Error.hpp"
#include <QString>

Error::Error(QWidget* parent, std::string message) : QWidget(parent){   
    createErrorWindow();
    createErrorButton();
    createErrorLabel(message);
}

void Error::createErrorLabel(std::string message){
    errorLabel.setText(QString::fromStdString(message));
    errorLabel.setWordWrap(true);
    errorLabel.setParent(this);
    errorLabel.setGeometry(10, 5, 80, 40);
    errorLabel.show();
}

void Error::createErrorButton(){
    errorButton.setText("Continue");
    errorButton.setParent(this);
    errorButton.setGeometry(30, 50, 40, 20);
    this->connect(&errorButton, &QPushButton::clicked, [this](){
        this->close();
        this->setAttribute(Qt::WA_DeleteOnClose);
    });
    errorButton.show();
}

void Error::createErrorWindow(){
    setWindowFlag(Qt::FramelessWindowHint);
    setGeometry(0, 0, 100, 80);
    show();

}