//
//  FontManager.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 24/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "FontManager.hpp"

using namespace QEngine;

FontManager::FontManager(){}
FontManager::~FontManager(){}

std::unordered_map<std::string, Font> FontManager::fontMap_;

void FontManager::quit(){
    for (auto it = fontMap_.begin(); it != fontMap_.end(); it++){
        it->second.free();
    }
}

bool FontManager::loadFont(const std::string& path, int fontSize, ColorRGBA fontColor){
    TTF_Font* newTTF;
    bool success = IOManager::loadFont(newTTF, path, fontSize);
    Font newFont;
    newFont.init(newTTF, fontColor);
    fontMap_[path] = newFont;
    return success;
}

Font* FontManager::getFont(const std::string& path){
    auto it = fontMap_.find(path);

    if (it == fontMap_.end()){
        printf("Unable to load font %s!\n", path.c_str());
        return NULL;
    }
    return &it->second;
}
