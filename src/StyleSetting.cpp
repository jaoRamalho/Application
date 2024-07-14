#include "StyleSetting.hpp"
#include <iostream>

StyleSetting::StyleSetting() : thema("dark"){
    styleMap["default"] = "config/darkStyle.css";
    styleMap["light"] = "config/lightStyle.css";
    styleMap["dark"] = "config/darkStyle.css";
}

StyleSetting::~StyleSetting(){

}

QString StyleSetting::getStyle(std::string styleName){
    std::ifstream file(styleMap[styleName]);
    if (!file.is_open()){
        std::cerr << "Error: Could not open file " << styleMap[styleName] << std::endl;
        return "";
    }

    std::string style((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    thema = styleName;
    return QString::fromStdString(style);
}

std::string StyleSetting::getThema(){
    return thema;
}