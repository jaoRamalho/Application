#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class NewsAPI{
private:
    string path_code_python;

public:
    NewsAPI();
    ~NewsAPI();

    nlohmann::json getNews(string country, vector<string> category);
    nlohmann::json getNews(string country, vector<string> category, string dataInicial, string dataFinal);


};

/*
int main(){
    Py_Initialize();
    PyRun_SimpleString("print('Hello World')");
    Py_Finalize();
    return 0;
};
*/