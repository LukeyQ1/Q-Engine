//
//  EventManager.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "EventManager.hpp"
#include "InputManager.hpp"

using namespace QEngine;

EventManager::EventManager(){}

EventManager::~EventManager(){}


void EventManager::updateState(){

    while(SDL_PollEvent(&sdlEvent_) != 0){
        //request quit
        if(sdlEvent_.type == SDL_QUIT){
            quit_ = true;
        }
        //Keyboard
        if(sdlEvent_.type == SDL_KEYDOWN){
            InputManager::pressKey(sdlEvent_.key.keysym.sym);
        }
        else if(sdlEvent_.type == SDL_KEYUP){
            InputManager::releaseKey(sdlEvent_.key.keysym.sym);
        }
        //Mouse
        else if (sdlEvent_.type == SDL_MOUSEBUTTONDOWN){
            InputManager::pressKey(sdlEvent_.button.button);
        }
        else if (sdlEvent_.type == SDL_MOUSEBUTTONUP){
            InputManager::releaseKey(sdlEvent_.button.button);
        }
        else if (sdlEvent_.type == SDL_MOUSEWHEEL){
            InputManager::setMouseScroll(sdlEvent_.wheel.x, sdlEvent_.wheel.y);
        }
        else if (sdlEvent_.type == SDL_MOUSEMOTION){
            InputManager::setMouseState();
        }
    }
}

bool EventManager::checkQuit(){
    return quit_;
}

SDL_Event EventManager::SDL(){
    return sdlEvent_;
}
