#include "LinkManager.hpp"

LinkManager::LinkManager(){
    createLinks();
}

LinkManager::~LinkManager(){

}

void LinkManager::createLinks(){
    addLink("icon-x", "imagens/icons/x.svg");

    addLink("icon-square", "imagens/icons/square.svg");

    addLink("icon-minimize", "imagens/icons/minimize.svg");

    addLink("icon-search", "imagens/icons/search.svg");

    addLink("icon-settings", "imagens/icons/settings.svg");

    addLink("icon-exit", "imagens/icons/exit.svg");

    addLink("icon-user", "imagens/icons/user.svg");

    addLink("icon-clip", "imagens/icons/clip.svg");

    addLink("icon-toggle-on", "imagens/icons/toggle-on.svg");
    addLink("icon-toggle-off", "imagens/icons/toggle-off.svg");

    addLink("icon-moon", "imagens/icons/moon.svg");

    addLink("icon-home", "imagens/icons/home.svg");
}

void LinkManager::addLink(std::string name, QString path){
    links[name] = path;
}

QString LinkManager::getLink(std::string link){
    if(links.find(link) != links.end()){
        return links[link];
    }
    return "";
}