//
//  Basics.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"

namespace QEngine{

    struct ColorRGBA : public SDL_Color{

        ColorRGBA(){
            r = 0;
            g = 0;
            b = 0;
            a = 1;
        }
        ColorRGBA(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 1){
            r = red;
            g = green;
            b = blue;
            a = alpha;
        }

        Uint8 a;
    };


    struct Rect : public SDL_Rect{

        Rect(){}
        Rect(int X, int Y, int W, int H) {
            x = X;
            y = Y;
            w = W;
            h = H;
        }
    };

    struct Point : public SDL_Point{

        Point(){
            x = 0;
            y = 0;
        }
        Point(int X, int Y){
            x = X;
            y = Y;
        }
    };

}
