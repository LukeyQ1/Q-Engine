//
//  Window.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"

namespace QEngine{


    class Window {

        public:
            Window();
            ~Window();

            bool init(std::string windowName, int width, int height);
            void quit();

            void FullscreenOn();
            void FullscreenOff();

            SDL_Window* SDL();

            int getWidth();
            int getHeight();

        private:
            SDL_Window* sdlWindow = NULL;
            int screenWidth = 0;
            int screenHeight = 0;
            bool fullscreen = false;
    };

}
