#include "Error.hpp"
#include <QString>

Error::Error(QWidget* parent, std::string message) : QWidget(parent){   
    createErrorWindow();
    createErrorLabel(message);
    createExitButton();
}

void Error::createErrorLabel(std::string message){
    errorLabel.setText(QString::fromStdString(message));
    errorLabel.setWordWrap(true);
    errorLabel.setParent(this);
    errorLabel.setAlignment(Qt::AlignCenter); // Centraliza o texto
    errorLabel.setGeometry(0, 0, width(), height());
    errorLabel.show();
}

void Error::createExitButton(){
    exitButton.setText("X");
    exitButton.setParent(this);
    exitButton.setGeometry(width() - 15, 0, 15, 15);
    this->connect(&exitButton, &QPushButton::clicked, [this](){
        this->close();
        this->setAttribute(Qt::WA_DeleteOnClose);
    });
    exitButton.show();
}

void Error::createErrorWindow(){
    setObjectName("Error");
    setWindowFlag(Qt::FramelessWindowHint);
    setGeometry(parentWidget()->width() / 2 - 75, parentWidget()->height()/2 - 115, 150, 50);
    show();

}