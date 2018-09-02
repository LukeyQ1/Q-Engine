//
//  AudioManager.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 28/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"

namespace QEngine{

    class SoundEffect{

        public:
            SoundEffect();
            SoundEffect(Mix_Chunk* effect);

            // -1 = forever; 0 = 1 play;
            void play(int loops = 0, bool wait = false);
            void stop();

        private:
            Mix_Chunk* effect_ = NULL;
            int channel_ = -1;
    };

    class Music{

        public:
            Music();
            Music(Mix_Music* music);

            // -1 = forever; 1 = 1 play;
            void play(int loops = 1);

            static void pause();
            static void resume();
            static void stop();

        private:
            Mix_Music* music_ = NULL;
    };


    class AudioManager {

        public:
            AudioManager();
            ~AudioManager();

            bool init();
            void quit();

            bool loadSoundEffect(const std::string& path);
            bool loadMusic(const std::string& path);

            static SoundEffect getSoundEffect(const std::string& path);
            static Music getMusic(const std::string& path);

        private:
            static std::unordered_map<std::string, Mix_Chunk*> effectMap_;
            static std::unordered_map<std::string, Mix_Music*> musicMap_;
    };

}
