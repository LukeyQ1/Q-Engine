//
//  ResourceManager.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 24/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "ResourceManager.hpp"

using namespace QEngine;

ResourceManager::ResourceManager(){}
ResourceManager::~ResourceManager(){}

std::unordered_map<std::string, Texture> ResourceManager::textureMap_;

void ResourceManager::quit(){
    for(auto it = textureMap_.begin(); it != textureMap_.end(); it++){
        it->second.free();
    }
}

bool ResourceManager::loadTexture(const std::string& path, ColorRGBA colorKey){
    Texture newTexture;
    bool success = IOManager::loadIMG(newTexture, path, colorKey);
    textureMap_[path] = newTexture;
    return success;
}

Texture* ResourceManager::getTexture(const std::string& path){
    auto it = textureMap_.find(path);

    if(it == textureMap_.end()){
        printf("Unable to load texture %s!\n", path.c_str());
        return NULL;
    }
    return &it->second;
}
