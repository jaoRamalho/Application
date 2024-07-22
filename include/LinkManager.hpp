#pragma once
#include <unordered_map>
#include <string>
#include <QString>

class LinkManager{
private:
    std::unordered_map<std::string, QString> links;
    void createLinks();
    void addLink(std::string name, QString path);

public:
    LinkManager();
    ~LinkManager();

    QString getLink(std::string link);
};