//
//  Timer.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Timer.hpp"

using namespace QEngine;

Timer::Timer(){
    startTicks_ = 0;
    pausedTicks_ = 0;

    paused_ = false;
    started_ = false;
}

void Timer::start(){
    started_ = true;
    paused_ = false;

    //Get the current time
    startTicks_ = SDL_GetTicks();
    pausedTicks_ = 0;
}

void Timer::stop(){
    started_ = false;
    paused_ = false;

    //Clear tick variables
    startTicks_ = 0;
    pausedTicks_ = 0;
}

void Timer::pause(){

    if(started_ && !paused_){

        paused_ = true;
        //Calculate the paused ticks
        pausedTicks_ = SDL_GetTicks() - startTicks_;
        startTicks_ = 0;
    }
}

void Timer::unpause(){

    if(started_ && paused_){

        paused_ = false;
        //Reset the starting ticks
        startTicks_ = SDL_GetTicks() - pausedTicks_;
        pausedTicks_ = 0;
    }
}

Uint32 Timer::getTicks(){
    //The actual timer time
    Uint32 time = 0;

    if(started_){
        if(paused_){
            time = pausedTicks_;
        }else{
            time = SDL_GetTicks() - startTicks_;
        }
    }
    return time;
}

bool Timer::isStarted(){
    return started_;
}

bool Timer::isPaused(){
    return paused_ && started_;
}
