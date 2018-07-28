//
//  Texture.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Texture.hpp"
#include "Renderer.hpp"

using namespace QEngine;

Texture::Texture(){}

Texture::~Texture(){
}

bool Texture::init(SDL_Texture* texture, int width, int height){
    if(texture == NULL){
        return false;
    }
    sdlTexture = texture;
    imgWidth = width;
    imgHeight = height;
    return true;
}
void Texture::free(){
    //Free texture if it exists
    if(sdlTexture != NULL){
        SDL_DestroyTexture(sdlTexture);
        sdlTexture = NULL;
        imgWidth = 0;
        imgHeight = 0;
        std::cout << "Deleted Texture" << std::endl;
    }
}


bool Texture::renderText(std::string textureText, TTF_Font* font, ColorRGBA textColor){
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if(textSurface != NULL){
        //Create texture from surface pixels
        sdlTexture = SDL_CreateTextureFromSurface(Renderer::SDL(), textSurface);
        if(sdlTexture == NULL){
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }else{
            //Get image dimensions
            imgWidth = textSurface->w;
            imgHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }
    else{
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }

    //Return success
    return sdlTexture != NULL;
}

void Texture::render(int x, int y, float scale, Rect* clip, double angle, Point* centerRotate, SDL_RendererFlip flip){
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, imgWidth, imgHeight };
    //Set clip rendering dimensions
    if(clip != NULL){
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    if(scale != 1){
        float newW = renderQuad.w;
        float newH = renderQuad.h;
        newW *= scale;
        newH *= scale;
        renderQuad.w = newW;
        renderQuad.h = newH;
    }
    if(sdlTexture != NULL){
        SDL_RenderCopyEx(Renderer::SDL(), sdlTexture, clip, &renderQuad, angle, centerRotate, flip);
    }
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue){
    SDL_SetTextureColorMod(sdlTexture, red, green, blue);
}
void Texture::setAlpha(Uint8 alpha){
    //Modulate texture alpha
    SDL_SetTextureAlphaMod(sdlTexture, alpha);
}
void Texture::setBlendMode(SDL_BlendMode blending){
    SDL_SetTextureBlendMode(sdlTexture, blending);
}

SDL_Texture* Texture::SDL() {
    return sdlTexture;
}
int Texture::getWidth(){
    return imgWidth;
}
int Texture::getHeight(){
    return imgHeight;
}
