//
//  Timer.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"

namespace QEngine{

    class Timer{

        public:
            Timer();

            void start();
            void stop();
            void pause();
            void unpause();

            Uint32 getTicks();

            bool isStarted();
            bool isPaused();

        private:
            Uint32 startTicks_;
            Uint32 pausedTicks_;

            bool paused_;
            bool started_;
        };

    class FpsTimer{

        public:
            static const int SAMPLE_RATE = 30;
            static const int MAX_STEPS = 5;

            FpsTimer();
            void init(float maxFPS);

            void start();
            void update();
            void limit();

            void setMaxFps(float maxFPS);

            float getCurrentFps();
            float getDeltaTime();
            float getMaxDeltaTime();

        private:
            float maxFps_;
            float currentFps_ = 0.0f;
            float fpsTime_; // Time SAMPLE_RATE frames ago
            int frameCount_ = 0;

            float startTime_;
            float previousFrameTime_;
    };

}
