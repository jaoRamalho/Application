#include "DataBase.hpp"
#include <iostream>

DataBase* DataBase::instance = nullptr;
std::string DataBase::pathLogins = "config/users.json";
DataBase::DataBase() {

}

DataBase::~DataBase(){

}

DataBase *DataBase::getInstance(){
    if (instance == nullptr){
        instance = new DataBase();
    }
    return instance;
}

bool DataBase::checkUsername(std::string username){
    nlohmann::json json = usersRegisters(); 

    for (const auto& user : json["users"]) {
        if (user["username"] == username) {
            return true;
        }
    }
    return false;
}

RegisterError DataBase::checkLoginDataBase(std::string username, std::string password)
{   
    if(username.empty()) return RegisterError::EMPTY_USERNAME;
    else if (password.empty()) return RegisterError::EMPTY_PASSWORD;

    nlohmann::json users = usersRegisters();
    for (const auto& user : users["users"]) {
        if (user["username"] == username){
            if(user["password"] == password) {
                return RegisterError::SUCCESS;
            }
            else {
                return RegisterError::PASSWORD_NOT_MATCH;
            }
        }
    }
    return RegisterError::USER_NOT_EXIST;
}

nlohmann::json DataBase::usersRegisters(){
    std::ifstream file(pathLogins);
    nlohmann::json users;

    if(!file.is_open()){
        std::cerr << "Erro ao abrir arquivo de logins" << std::endl;
        return users; 
    }

    file >> users;
    return users;
}

RegisterError DataBase::newUser(std::string name, std::string username, std::string password, std::string confirmPassword){
    
    if (name.empty())
        return RegisterError::EMPTY_NAME;
    else if (username.empty())
        return RegisterError::EMPTY_USERNAME;
    else if (password.empty())
        return RegisterError::EMPTY_PASSWORD;
    else if (password != confirmPassword)
        return RegisterError::PASSWORD_NOT_MATCH;

    nlohmann::json json = usersRegisters(); 


    for (const auto& user : json["users"]) {
        if (user["username"] == username) {
            return RegisterError::USERNAME_ALREADY_EXISTS;
        }
    }

    // Criar um novo objeto JSON para o usuário
    nlohmann::json newUser = {
        {"name", name},
        {"username", username},
        {"password", password},
        {"role", "user"}
    };

    // Adicionar o novo usuário ao array 'users'
    json["users"].push_back(newUser);

    // Salvar o JSON modificado de volta ao arquivo
    std::ofstream outputFile(pathLogins);
    outputFile << json.dump(4); // Formatação com 4 espaços de indentação
    outputFile.close();

    return RegisterError::SUCCESS;
}

std::string DataBase::messageError(RegisterError erro){
    //mensagens para ser exibida ao usuario por diferentes erros
    
    switch (erro){
        case RegisterError::EMPTY_NAME :
            return "Empty name field";
            break;
        case RegisterError::EMPTY_USERNAME :
            return "Empty username field";
            break;
        case RegisterError::EMPTY_PASSWORD :
            return "Empty password field";
            break;
        case RegisterError::PASSWORD_NOT_MATCH:
            return "Password not match";
            break;
        case RegisterError::USERNAME_ALREADY_EXISTS :
            return "Username alredy exists";
            break;
        case RegisterError::USER_NOT_EXIST :
            return "User does not exist";
            break;
        default :
            return "SUCCESS";
    };
}
