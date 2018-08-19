//
//  MainGame.hpp
//  Q-Test
//
//  Created by Luke Quinlan on 14/08/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Q-Engine.h"

namespace QEngine{

    class MainGame{

        public:
            MainGame(std::string screenName, int screenWidth, int screenHeight, float maxFps = 60);
            ~MainGame();

            void run();

        private:
            Window window;
            Renderer renderer;

        protected:
            virtual bool loadAssets() = 0;
            virtual void setup() = 0;

            virtual void update(float deltaTime) = 0;
            virtual void update() = 0;
            virtual void draw() = 0;

            virtual void onQuit() = 0;

            InputManager IM;
            EventManager EM;
            ResourceManager RM;
            FontManager FM;
            AudioManager AM;

            Camera CAM;

            FpsTimer FPS;
            float maxFPS = 60;

            int SCREEN_WIDTH;
            int SCREEN_HEIGHT;

    };

}
