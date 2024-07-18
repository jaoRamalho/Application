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
    errorLabel.setAlignment(Qt::AlignCenter); // Centraliza o texto
    errorLabel.setGeometry(10, 10, width() - 20, height() / 2 + 20);
    errorLabel.show();
}

void Error::createErrorButton(){
    errorButton.setText("Continue");
    errorButton.setParent(this);
    errorButton.setGeometry(width()/2 - 30, height() - 37, 60, 30);
    this->connect(&errorButton, &QPushButton::clicked, [this](){
        this->close();
        this->setAttribute(Qt::WA_DeleteOnClose);
    });
    errorButton.show();
}

void Error::createErrorWindow(){
    setObjectName("Error");
    setWindowFlag(Qt::FramelessWindowHint);
    setGeometry(parentWidget()->width() / 2 - 100, parentWidget()->height()/2 - 75, 200, 150);
    show();

}