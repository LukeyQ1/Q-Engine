//
//  Font.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 29/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Font.hpp"
#include "IOManager.hpp"

using namespace QEngine;

Font::Font(){}

bool Font::init(TTF_Font* font, ColorRGBA fontColor){
    if(font == NULL){
        return false;
    }
    sdlFont_ = font;
    fontColor_ = fontColor;
    return true;
}
void Font::free(){
    TTF_CloseFont(sdlFont_);
    sdlFont_ = NULL;
}

void Font::render(int x, int y, std::string text){
    // Render Text Surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(sdlFont_, text.c_str(), fontColor_);
    SDL_Texture* textTexture;
    int width, height;

    // Create Texture from Surface
    if(textSurface != NULL){
        textTexture = SDL_CreateTextureFromSurface(Renderer::SDL(), textSurface);
        if(textTexture == NULL){
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
            return;
        }else{
            width = textSurface->w;
            height = textSurface->h;
        }
    }else{
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }
    // Render to Screen
    SDL_Rect renderQuad = { x, y, width, height };
    if(textTexture != NULL){
        SDL_RenderCopy(Renderer::SDL(), textTexture, NULL, &renderQuad);
    }
    // Delete Temporarys
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    textTexture = NULL;
}

void Font::setColor(ColorRGBA newColor){
    fontColor_ = newColor;
}

int Font::getHeight(){
    return TTF_FontHeight(sdlFont_);
}

