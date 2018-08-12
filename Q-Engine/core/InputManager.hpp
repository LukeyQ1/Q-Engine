//
//  InputManager.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Input.hpp"

namespace QEngine{

    class InputManager{

        public:
            InputManager();
            ~InputManager();


            static void update();

            static void pressKey(unsigned int keyID);
            static void releaseKey(unsigned int keyID);

            //Held Down
            static bool isKeyDown(keyCode keyID);
            //Single Press
            static bool isKeyPressed(keyCode keyID);

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
