//
//  Collision.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 02/08/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Collider.hpp"

// REVISIT: Needs improving

namespace QEngine{

    class Collision{

        public:
            // Set Collision direction and depth
            static bool AABB_AABB(const Collider &A, const Collider &B);
            static bool AABB_CIRCLE(const Collider &A, const Collider &B, bool reverse = false);
            static bool CIRCLE_CIRCLE(const Collider &A, const Collider &B);

            // Set Collision point
            static bool AABB_LINE(const glm::vec2& initialPosition, const glm::vec2 &finalPosition, const Collider &A);
            static bool CIRCLE_LINE(const glm::vec2& initialPosition, const glm::vec2 &finalPosition, const Collider &A);
            static bool LINE_LINE(const glm::vec2& initialA, const glm::vec2 &finalA, const glm::vec2& initialB, const glm::vec2 &finalB);

            static glm::vec2 point;
            static glm::vec2 depth;
            static glm::vec2 direction;

        private:
            static void reset();
    };

}
