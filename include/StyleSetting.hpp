#pragma once 
#include <string>
#include <fstream>
#include <QString>
#include <unordered_map>

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