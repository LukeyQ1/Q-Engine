//
//  Camera.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 25/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace QEngine{

    class Camera{

        public:
            Camera();
            ~Camera();

            void init(int screenWidth, int screenHeight);

            static glm::vec2 screenToWorld(glm::vec2 screenCoords); // Mouse
            static void screenToWorld(int& x, int& y);

            static glm::vec2 worldToScreen(glm::vec2 worldCoords); // Objects
            static void worldToScreen(int& x, int& y);

            // static bool inView(const glm::vec2& position, const glm::vec2& size); // Camera Culling - only render if visible

            void moveCamera(const glm::vec2& translate);
            void setPosition(const glm::vec2& newPosition);
            void setScale(float scale);

            static void scaleObject(int& w, int& h);
            static glm::vec2 getPosition();
            static float getScale();

        private:
            static glm::vec2 position_;
            static float scale_;

            static int screenWidth_;
            static int screenHeight_;
    };

}
