//
//  Sprite.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 26/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Sprite.hpp"
#include "ResourceManager.hpp"

using namespace QEngine;

Sprite::~Sprite(){}
Sprite::Sprite(){}

void Sprite::init(int x, int y, int width, int height, const std::string& texturePath) {
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
    texture_ = ResourceManager::getTexture(texturePath);
}

void Sprite::init(const std::string& texturePath) {
    texture_ = ResourceManager::getTexture(texturePath);
    x_ = 0;
    y_ = 0;
    width_ = texture_->getWidth();
    height_ = texture_->getHeight();
}

void Sprite::render(int x, int y, float scale, double angle, Point* centerRotate, SDL_RendererFlip flip){
    Rect clip(x_, y_, width_, height_);
    texture_->render(x, y, scale, &clip, angle, centerRotate, flip);
}

Texture* Sprite::getTexture(){
    return texture_;
}
int Sprite::getWidth(){
    return width_;
}
int Sprite::getHeight(){
    return height_;
}
