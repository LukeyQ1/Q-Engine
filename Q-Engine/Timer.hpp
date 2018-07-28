//
//  Timer.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"

namespace QEngine {

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

}
