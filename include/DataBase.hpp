#pragma once
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

class DataBase{
private:
    static std::string pathLogins;
    static DataBase* instance;

    DataBase();
public:
    ~DataBase();

    static DataBase* getInstance();
    static bool checkLoginDataBase(std::string username, std::string password);
    static nlohmann::json usersRegisters();
    static bool newUser(std::string username, std::string password);
};