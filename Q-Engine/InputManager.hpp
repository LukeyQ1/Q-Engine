//
//  InputManager.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"

namespace QEngine{

    enum {
        K_UP = SDLK_UP,
        K_DOWN = SDLK_DOWN,
        K_LEFT = SDLK_LEFT,
        K_RIGHT = SDLK_RIGHT,

        K_Q = SDLK_q,
        K_W = SDLK_w,
        K_E = SDLK_e,
        K_R = SDLK_r,

        K_A = SDLK_a,
        K_S = SDLK_s,
        K_D = SDLK_d,


        M_LEFT = SDL_BUTTON_LEFT,
        M_RIGHT = SDL_BUTTON_RIGHT,
        M_MIDDLE = SDL_BUTTON_MIDDLE

    };

    class InputManager{

    public:
        InputManager();
        ~InputManager();


        static void update();

        static void pressKey(unsigned int keyID);
        static void releaseKey(unsigned int keyID);

        //Held Down
        static bool isKeyDown(unsigned int keyID);
        //Single Press
        bool isKeyPressed(unsigned int keyID);

        static void setMouseScroll(int x, int y);
        static void setMouseState();

        //false if not moving
        static bool getMousePos(int& x, int& y);
        //false if no scroll
        static bool getMouseScroll(int& x, int &y);

    private:
        static std::unordered_map<unsigned int, bool> keyMap_;
        static std::unordered_map<unsigned int, bool> previouskeyMap_;

        static bool mouseState_;
        static int mouseScrollX_;
        static int mouseScrollY_;

    };

}
