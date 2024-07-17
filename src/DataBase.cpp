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

bool DataBase::checkLoginDataBase(std::string username, std::string password)
{
    nlohmann::json users = usersRegisters();
    if(users[username] == password){ return true; }
    else { return false; }
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

bool DataBase::newUser(std::string username, std::string password){
    nlohmann::json users = usersRegisters();
    if (users.find(username) != users.end())
        return false;
    
    users[username] = password;
    std::ofstream file(pathLogins);
    
    file << users.dump(4);
    file.close();
    
    return true;
}