//
//  Font.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 29/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Renderer.hpp"
#include "Basics.hpp"

namespace QEngine{

    class Font{

        public:
            Font();

            bool init(TTF_Font* font, ColorRGBA fontColor = {0,0,0});
            void free();

            void render(int x, int y, std::string text);

            void setColor(ColorRGBA newColor);

            int getHeight();

        private:
            TTF_Font* sdlFont_ = NULL;
            ColorRGBA fontColor_ = {0,0,0};
    };

}
