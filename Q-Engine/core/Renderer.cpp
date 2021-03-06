//
//  Renderer.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Renderer.hpp"

using namespace QEngine;

Renderer::Renderer(){}
Renderer::~Renderer(){}

SDL_Renderer* Renderer::sdlRenderer_;

bool Renderer::init(Window window){

    sdlRenderer_ = SDL_CreateRenderer(window.SDL(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if(sdlRenderer_ == NULL){
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    else{
        SDL_SetRenderDrawColor(sdlRenderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    return true;
}
void Renderer::quit(){
    SDL_DestroyRenderer(sdlRenderer_);
    sdlRenderer_ = NULL;
}

void Renderer::clear(){
    SDL_RenderClear(sdlRenderer_);
}
void Renderer::update(){
    SDL_RenderPresent(sdlRenderer_);
}

void Renderer::setColor(ColorRGBA color){
    SDL_SetRenderDrawColor(sdlRenderer_, color.r, color.g, color.b, color.a);
}

SDL_Renderer* Renderer::SDL(){
    return sdlRenderer_;
}
