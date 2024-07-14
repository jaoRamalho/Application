#include "StyleSetting.hpp"
#include <iostream>

StyleSetting* StyleSetting::instance = nullptr;
StyleSetting::StyleSetting(){
    styleMap["default"] = "config/darkStyle.css";
    styleMap["light"] = "config/lightStyle.css";
    styleMap["dark"] = "config/darkStyle.css";
}

StyleSetting::~StyleSetting(){

}

StyleSetting* StyleSetting::getInstance(){
    if(instance == nullptr){
        instance = new StyleSetting();
    }
    return instance;
}

QString StyleSetting::getStyle(std::string styleName){
    std::ifstream file(styleMap[styleName]);
    if (!file.is_open()){
        std::cerr << "Error: Could not open file " << styleMap[styleName] << std::endl;
        return "";
    }

    std::string style((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    return QString::fromStdString(style);
}