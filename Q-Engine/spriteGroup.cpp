//
//  spriteGroup.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "spriteGroup.hpp"

using namespace QEngine;

spriteGroup::spriteGroup(){}
spriteGroup::~spriteGroup(){}


void spriteGroup::addSprite(QEngine::Sprite newSprite, int name) {
    spriteList_[name] = newSprite;
}


Sprite spriteGroup::getSprite(int name) {
    return spriteList_[name];
}
