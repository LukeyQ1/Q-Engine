//
//  IOManager.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 24/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "IOManager.hpp"

using namespace QEngine;

bool IOManager::loadIMG(Texture& newTexture, const std::string& path, ColorRGBA colorKey){

    SDL_Texture* sdlTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL){
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        return false;
    }else{

        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, colorKey.r, colorKey.g, colorKey.b));
        //Create texture from surface pixels
        sdlTexture = SDL_CreateTextureFromSurface(Renderer::SDL(), loadedSurface);
        if(sdlTexture == NULL){
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
            return false;
        }else{
            newTexture.init(sdlTexture, loadedSurface->w, loadedSurface->h);
        }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return true;
}

bool IOManager::loadSoundEffect(Mix_Chunk*& newEffect, const std::string& path){
    newEffect = Mix_LoadWAV(path.c_str());
    if(newEffect == NULL){
        printf( "Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    return true;
}

bool IOManager::loadMusic(Mix_Music*& newMusic, const std::string& path){
    newMusic = Mix_LoadMUS(path.c_str());
    if(newMusic == NULL){
        printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    return true;
}

bool IOManager::loadFont(TTF_Font*& newFont, const std::string& path, int fontSize){
    newFont = TTF_OpenFont(path.c_str(), fontSize);
    if(newFont == NULL){
        printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
        return false;
    }
    return true;
}
