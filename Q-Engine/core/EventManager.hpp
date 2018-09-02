//
//  EventManager.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"

namespace QEngine{

    class EventManager{

        public:
            EventManager();
            ~EventManager();

            void updateState();

            bool checkQuit();

            SDL_Event SDL();

        private:
            SDL_Event sdlEvent_;
            bool quit_ = false;
    };

}
