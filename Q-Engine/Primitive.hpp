//
//  Primitives.hpp
//  Q-Test
//
//  Created by Luke Quinlan on 01/08/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Basics.hpp"
#include "Renderer.hpp"

namespace QEngine{

    class Primitive{

        public:
            static void drawLine(glm::vec2 initialPos, glm::vec2 finalPos, ColorRGBA color){
                Renderer::setColor(color);
                SDL_RenderDrawLine(Renderer::SDL(), initialPos.x, initialPos.y, finalPos.x, finalPos.y);
            }

            static void drawPoint(glm::vec2 position, ColorRGBA color){
                Renderer::setColor(color);
                SDL_RenderDrawPoint(Renderer::SDL(), position.x, position.y);
            }

            static void drawRect(glm::vec2 position, glm::vec2 size, ColorRGBA color){
                Renderer::setColor(color);
                SDL_Rect tmp;
                tmp.x = position.x;
                tmp.y = position.y;
                tmp.w = size.x;
                tmp.h = size.y;
                SDL_RenderDrawRect(Renderer::SDL(), &tmp);
            }
            static void drawFillRect(glm::vec2 position, glm::vec2 size, ColorRGBA color){
                Renderer::setColor(color);
                SDL_Rect tmp;
                tmp.x = position.x;
                tmp.y = position.y;
                tmp.w = size.x;
                tmp.h = size.y;
                SDL_RenderFillRect(Renderer::SDL(), &tmp);
            }
    };

}
