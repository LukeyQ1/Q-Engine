//
//  Timer.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Timer.hpp"

using namespace QEngine;
//
// Basic Timer
//
Timer::Timer(){
    startTicks_ = 0;
    pausedTicks_ = 0;

    paused_ = false;
    started_ = false;
}

void Timer::start(){
    started_ = true;
    paused_ = false;

    startTicks_ = SDL_GetTicks();   // Get the current time
    pausedTicks_ = 0;
}
void Timer::stop(){
    started_ = false;
    paused_ = false;

    startTicks_ = 0;     // Clear tick variables
    pausedTicks_ = 0;
}

void Timer::pause(){
    if(started_ && !paused_){

        paused_ = true;
        pausedTicks_ = SDL_GetTicks() - startTicks_;    // Calculate the paused ticks
        startTicks_ = 0;
    }
}
void Timer::unpause(){
    if(started_ && paused_){

        paused_ = false;
        startTicks_ = SDL_GetTicks() - pausedTicks_;    // Reset the starting ticks
        pausedTicks_ = 0;
    }
}

Uint32 Timer::getTicks(){
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
//
// FPS Limiter and Timestep
//
FpsTimer::FpsTimer(){}
void FpsTimer::init(float maxFPS){
    maxFps_ = maxFPS;
    frameCount_ = 0;
    previousFrameTime_ = SDL_GetTicks();
}

void FpsTimer::start(){
    startTime_ = SDL_GetTicks();
}

void FpsTimer::update(){
    float currentTime = SDL_GetTicks();
    if(frameCount_ == SAMPLE_RATE){
        frameCount_ = 0;
        currentFps_ = (float)SAMPLE_RATE*1000.0f / (currentTime - fpsTime_);
        fpsTime_ = currentTime;
    }
    frameCount_++;
    previousFrameTime_ = startTime_;
}
void FpsTimer::limit(){
    float currentTime = SDL_GetTicks();
    if(frameCount_ == SAMPLE_RATE){
        frameCount_ = 0;
        currentFps_ = (float)SAMPLE_RATE*1000.0f / (currentTime - fpsTime_);
        fpsTime_ = currentTime;
    }
    float frameTime = currentTime - startTime_;
    if (1000.0f / maxFps_ > frameTime) {
            SDL_Delay((Uint32)(1000.0f / maxFps_ - frameTime));
    }
    frameCount_++;
    previousFrameTime_ = startTime_;
}

void FpsTimer::setMaxFps(float maxFPS){
    maxFps_ = maxFPS;
}

float FpsTimer::getCurrentFps(){
    return currentFps_;
}
float FpsTimer::getDeltaTime(){
    return (startTime_ - previousFrameTime_) / 1000.0f;
}
float FpsTimer::getMaxDeltaTime(){
    return 1.0f / maxFps_;
}
