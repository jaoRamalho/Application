#pragma once
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

// Enum de erros possiveis ao registrar um novo usuario e fazer login
enum RegisterError{
    EMPTY_NAME,
    EMPTY_USERNAME,
    EMPTY_PASSWORD,
    PASSWORD_NOT_MATCH,
    USERNAME_ALREADY_EXISTS,
    USER_NOT_EXIST,
    SUCCESS    
};


// Classe para manipular o banco de dados de usuarios (o json de usuarios registrados)
class DataBase{
private:
    static std::string pathLogins;
    static DataBase* instance;

    DataBase();
public:
    ~DataBase();

    static DataBase* getInstance();
    static bool checkUsername(std::string username);
    static RegisterError checkLoginDataBase(std::string username, std::string password);
    static nlohmann::json usersRegisters();
    static RegisterError newUser(std::string name, std::string username, std::string password, std::string confirmPassword);
    static std::string messageError(RegisterError erro);
};