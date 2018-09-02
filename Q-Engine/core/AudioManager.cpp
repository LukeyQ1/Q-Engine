//
//  AudioManager.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 28/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "AudioManager.hpp"
#include "IOManager.hpp"

using namespace QEngine;
//
// Sound Effects
//
SoundEffect::SoundEffect(){}
SoundEffect::SoundEffect(Mix_Chunk* effect) : effect_(effect){}

void SoundEffect::play(int loops, bool wait){
    if(channel_ == -1){ // Only play once
        channel_ = Mix_PlayChannel(-1, effect_, loops);
    }else{
       if(!wait || !Mix_Playing(channel_)){ // Don't restart sound effect if still playing
            Mix_PlayChannel(channel_, effect_, loops);
       }
    }
}
void SoundEffect::stop(){
    Mix_HaltChannel(channel_);
}
//
// Music
//
Music::Music(){}
Music::Music(Mix_Music* music) : music_(music){}

void Music::play(int loops){
    Mix_PlayMusic(music_, loops);
}
void Music::pause(){
    Mix_PauseMusic();
}
void Music::resume(){
    Mix_ResumeMusic();
}
void Music::stop(){
    Mix_HaltMusic();
}
//
// Audio Manager
//
AudioManager::AudioManager(){}
AudioManager::~AudioManager(){}

std::unordered_map<std::string, Mix_Chunk*> AudioManager::effectMap_;
std::unordered_map<std::string, Mix_Music*> AudioManager::musicMap_;

bool AudioManager::init(){
    Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }
    return true;
}
void AudioManager::quit(){
    for (auto it = effectMap_.begin(); it != effectMap_.end(); it++){
        Mix_FreeChunk(it->second);
    }
    for (auto it = musicMap_.begin(); it != musicMap_.end(); it++){
        Mix_FreeMusic(it->second);
    }
    Mix_Quit();
}

bool AudioManager::loadSoundEffect(const std::string& path){
    Mix_Chunk* newEffect;
    bool success = IOManager::loadSoundEffect(newEffect, path);
    effectMap_[path] = newEffect;
    return success;
}
bool AudioManager::loadMusic(const std::string& path){
    Mix_Music* newMusic;
    bool success = IOManager::loadMusic(newMusic, path);
    musicMap_[path] = newMusic;
    return success;
}

SoundEffect AudioManager::getSoundEffect(const std::string& path){
    return SoundEffect(effectMap_[path]);
}
Music AudioManager::getMusic(const std::string& path){
    return Music(musicMap_[path]);
}
