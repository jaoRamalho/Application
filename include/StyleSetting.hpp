#pragma once 
#include <string>
#include <fstream>
#include <QString>
#include <unordered_map>

class StyleSetting{
private:
    static StyleSetting* instance;
    std::unordered_map<std::string, std::string> styleMap;

    StyleSetting();

public:
    ~StyleSetting();

    static StyleSetting* getInstance();
    QString getStyle(std::string styleName);
};