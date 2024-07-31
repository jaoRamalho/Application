#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class NewsAPI{
private:
    static string path_code_python;


    static std::string request(const char* cmd);
public:
    NewsAPI();
    ~NewsAPI();

    static nlohmann::json getNews(string country, vector<string> category);
    static nlohmann::json getNews(string country, vector<string> category, string dataInicial, string dataFinal);


};

/*
int main(){
    Py_Initialize();
    PyRun_SimpleString("print('Hello World')");
    Py_Finalize();
    return 0;
};
*/