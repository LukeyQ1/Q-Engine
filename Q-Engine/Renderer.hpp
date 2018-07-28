//
//  Renderer.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Window.hpp"

namespace QEngine {

    class Window;

    class Renderer{

        public:
            Renderer();
            ~Renderer();

            bool init(Window window);
            void quit();

            void clear();
            void update();

            void setColour(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

            static SDL_Renderer* SDL();

        private:
            static SDL_Renderer* sdlRenderer_;
    };

}
