#pragma once 
#include <string>
#include <fstream>
#include <QString>
#include <unordered_map>


// classe para controlar as configurcoes de exibicao (style)
class StyleSetting{
private:
    std::unordered_map<std::string, std::string> styleMap;
    std::string thema;

public:
    StyleSetting();
    ~StyleSetting();

    static StyleSetting* getInstance();
    QString getStyle(std::string styleName);
    std::string getThema();
};