//
//  Texture.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Renderer.hpp"
#include "Basics.hpp"

namespace QEngine{

    class Texture{

        public:
            Texture();
            ~Texture();

            bool init(SDL_Texture* texture, int width, int height);
            void free();

            // Set color modulation
            void setColor(Uint8 red, Uint8 green, Uint8 blue);
            void setAlpha(Uint8 alpha);
            // Set blending
            void setBlendMode(SDL_BlendMode blending);

            // Renders texture at given point
            void render(int x, int y, float scale = 1.0f, Rect* clip = NULL, double angle = 0.0, Point* centerRotate = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

            SDL_Texture* SDL();
            int getWidth();
            int getHeight();

        private:
            SDL_Texture* sdlTexture = NULL;
            int imgWidth = 0;
            int imgHeight = 0;
    };

}
