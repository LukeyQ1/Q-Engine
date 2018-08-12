//
//  Sprite.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 26/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Texture.hpp"

namespace QEngine{

    class Sprite{

    public:
        Sprite();
        ~Sprite();

        void init(int x, int y, int width, int height, const std::string& texturePath);
        void init(const std::string& texturePath);

        void render(int x, int y, float scale = 1.0f, double angle = 0, Point* centerRotate = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

        Texture* getTexture();
        int getWidth();
        int getHeight();

    private:
        int x_;
        int y_;
        int width_;
        int height_;
        Texture* texture_;
    };

}
