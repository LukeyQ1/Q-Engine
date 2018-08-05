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

    enum{
        K_UP = SDLK_UP,
        K_DOWN = SDLK_DOWN,
        K_LEFT = SDLK_LEFT,
        K_RIGHT = SDLK_RIGHT,
        
        K_SPACE = SDLK_SPACE,
        K_ENTER = SDLK_RETURN,
        
        K_1 = SDLK_1,
        K_2 = SDLK_2,
        K_3 = SDLK_3,
        K_4 = SDLK_4,

        K_Q = SDLK_q,
        K_W = SDLK_w,
        K_E = SDLK_e,
        K_R = SDLK_r,

        K_A = SDLK_a,
        K_S = SDLK_s,
        K_D = SDLK_d,
        K_F = SDLK_f,


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
        static bool isKeyPressed(unsigned int keyID);

        static void setMouseScroll(int x, int y);
        static void setMouseState();

        //false if not moving
        static glm::vec2 getMousePos();
        static bool getMousePos(int& x, int& y);
        //false if no scroll
        static glm::vec2 getMouseScroll();
        static bool getMouseScroll(int& x, int &y);

    private:
        static std::unordered_map<unsigned int, bool> keyMap_;
        static std::unordered_map<unsigned int, bool> previouskeyMap_;

        static bool mouseState_;
        static int mouseScrollX_;
        static int mouseScrollY_;
    };

}
