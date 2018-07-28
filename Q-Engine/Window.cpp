//
//  Window.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Window.hpp"

using namespace QEngine;

Window::Window(){};
Window::~Window(){};

bool Window::init(std::string windowName, int sWidth, int sHeight) {

    screenWidth = sWidth;
    screenHeight = sHeight;

    sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sWidth, sHeight, SDL_WINDOW_SHOWN);
    if(sdlWindow == NULL){
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

void Window::quit(){
    SDL_DestroyWindow(sdlWindow);
    sdlWindow = NULL;
}

void Window::FullscreenOn(){
    if(!fullscreen){
        SDL_SetWindowFullscreen(sdlWindow, SDL_TRUE);
        fullscreen = true;
    }
}
void Window::FullscreenOff(){
    if(fullscreen){
        SDL_SetWindowFullscreen(sdlWindow, SDL_FALSE);
        fullscreen = false;
    }
}

int Window::getWidth(){
    return screenWidth;
}
int Window::getHeight(){
    return screenHeight;
}
SDL_Window* Window::SDL(){
    return sdlWindow;
}
