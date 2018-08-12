//
//  SpriteGroup.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "SpriteGroup.hpp"

using namespace QEngine;

SpriteGroup::SpriteGroup(){}
SpriteGroup::~SpriteGroup(){}


void SpriteGroup::addSprite(QEngine::Sprite newSprite, int name) {
    spriteList_[name] = newSprite;
}


Sprite SpriteGroup::getSprite(int name) {
    return spriteList_[name];
}
