#include "NewsAPI.hpp"


std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
};

NewsAPI::NewsAPI() : path_code_python("NewsAPI/NewsAPI.py"){

}

NewsAPI::~NewsAPI(){

}

nlohmann::json NewsAPI::getNews(string country, vector<string> category){
    std::string categoryStr;
    for(auto& str : category) { categoryStr += str + " "; }

    // Construa o comando para executar o script Python
    std::string command = "python " + path_code_python;
    std::string output = exec(command.c_str());

    // Assumindo que a saída é um JSON como string
    return nlohmann::json::parse(output);
}

nlohmann::json NewsAPI::getNews(string country, vector<string> category, string dataInicial, string dataFinal){

}