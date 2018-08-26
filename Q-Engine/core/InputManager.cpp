//
//  InputManager.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "InputManager.hpp"

using namespace QEngine;

InputManager::InputManager(){}
InputManager::~InputManager(){}

std::unordered_map<unsigned int, bool> InputManager::keyMap_;
std::unordered_map<unsigned int, bool> InputManager::previouskeyMap_;
bool InputManager::mouseState_;
int InputManager::mouseScrollX_;
int InputManager::mouseScrollY_;

void InputManager::update(){
    for(auto it = keyMap_.begin(); it != keyMap_.end(); it++){
        previouskeyMap_[it->first] = it->second;
    }
    mouseScrollX_ = 0;
    mouseScrollY_ = 0;
    mouseState_ = false;
}

void InputManager::pressKey(unsigned int keyID){
    keyMap_[keyID] = true;
}
void InputManager::releaseKey(unsigned int keyID){
    keyMap_[keyID] = false;
}

bool InputManager::isKeyDown(keyCode keyID){
    auto it = keyMap_.find(keyID);
    if(it != keyMap_.end()){
        return it->second;
    }
    return false;
}
bool InputManager::isKeyPressed(keyCode keyID){
    auto it = previouskeyMap_.find(keyID);
    bool wasDown;
    if(it != previouskeyMap_.end()){
        wasDown = it->second;
    }else{
        wasDown = false;
    }

    if(isKeyDown(keyID) && !wasDown){
        return true;
    }
    return false;
}

void InputManager::setMouseScroll(int x, int y){
    mouseScrollX_ = x;
    mouseScrollY_ = y;
}
void InputManager::setMouseState(){
    mouseState_ = true;
}

glm::vec2 InputManager::getMousePos(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    return glm::vec2((float)x, (float)y);
}
glm::vec2 InputManager::getMouseScroll(){
    return glm::vec2(mouseScrollX_, mouseScrollY_);
}
bool InputManager::getMouseState(){
    return mouseState_;
}

