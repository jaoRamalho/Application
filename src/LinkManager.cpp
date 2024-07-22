#include "LinkManager.hpp"

LinkManager::LinkManager(){
    createLinks();
}

LinkManager::~LinkManager(){

}

void LinkManager::createLinks(){

    addLink("icon-x-white", "imagens/icons/x-white.ico");
    addLink("icon-x-black", "imagens/icons/x-black.ico");
    
    addLink("icon-square-white", "imagens/icons/square-white.ico");
    addLink("icon-square-black", "imagens/icons/square-black.ico");
    
    addLink("icon-minimize-white", "imagens/icons/minimize-white.ico");
    addLink("icon-minimize-black", "imagens/icons/minimize-black.ico");
    
    addLink("icon-search-white", "imagens/icons/search-white.ico");
    addLink("icon-search-black", "imagens/icons/search-black.ico");

    addLink("icon-settings-white", "imagens/icons/settings-white.ico");
    addLink("icon-settings-black", "imagens/icons/settings-black.ico");
    
    addLink("icon-exit-white", "imagens/icons/exit-white.ico");
    addLink("icon-exit-black", "imagens/icons/exit-black.ico");

    addLink("icon-user-white", "imagens/icons/user-white.ico");
    addLink("icon-user-black", "imagens/icons/user-black.ico");

    addLink("icon-insignes-white", "imagens/icons/clip-white.ico");
    addLink("icon-insignes-black", "imagens/icons/clip-black.ico");
    
    addLink("icon-toggle-on", "imagens/icons/toggle-on.ico");
    addLink("icon-toggle-off", "imagens/icons/toggle-off.ico");

    addLink("icon-moon-white", "imagens/icons/moon-white.ico");

    addLink("icon-home-white", "imagens/icons/home-white.ico");
    addLink("icon-home-black", "imagens/icons/home-black.ico");
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