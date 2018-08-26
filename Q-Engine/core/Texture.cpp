//
//  Texture.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Texture.hpp"
#include "Renderer.hpp"
#include "Camera.hpp"

using namespace QEngine;

Texture::Texture(){}
Texture::~Texture(){}

bool Texture::init(SDL_Texture* texture, int width, int height){
    if(texture == NULL){
        return false;
    }
    sdlTexture_ = texture;
    textureWidth_ = width;
    textureHeight_ = height;
    return true;
}
void Texture::free(){
    if(sdlTexture_ != NULL){
        SDL_DestroyTexture(sdlTexture_);
        sdlTexture_ = NULL;
        textureWidth_ = 0;
        textureHeight_ = 0;
    }
}

void Texture::render(int x, int y, float scale, Rect* clip, double angle, Point* centerRotate, SDL_RendererFlip flip){
    if(sdlTexture_ == NULL){
        return;
    }
    SDL_Rect renderQuad = { x, y, textureWidth_, textureHeight_ };
    // Clip Texture
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
    
    if(Camera::inView(glm::vec2(renderQuad.x, renderQuad.y), glm::vec2(renderQuad.w, renderQuad.h))){
        SDL_RenderCopyEx(Renderer::SDL(), sdlTexture_, clip, &renderQuad, angle, centerRotate, flip);
    }
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue){
    SDL_SetTextureColorMod(sdlTexture_, red, green, blue);
}
void Texture::setAlpha(Uint8 alpha){
    SDL_SetTextureAlphaMod(sdlTexture_, alpha);
}
void Texture::setBlendMode(SDL_BlendMode blending){
    SDL_SetTextureBlendMode(sdlTexture_, blending);
}

SDL_Texture* Texture::SDL(){
    return sdlTexture_;
}
int Texture::getWidth(){
    return textureWidth_;
}
int Texture::getHeight(){
    return textureHeight_;
}
