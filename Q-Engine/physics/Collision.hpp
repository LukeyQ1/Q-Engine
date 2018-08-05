//
//  Collision.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 02/08/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Collider.hpp"

// REVISIT: Needs improving

namespace QEngine{

    class Collision{

        public: // Return NULL if miss.
            // Return Collision Depth
            static glm::vec2* AABB_AABB(const Collider &A, const Collider &B);
            static glm::vec2* AABB_CIRCLE(const Collider &A, const Collider &B, bool reverse = false){ return NULL; }
            static glm::vec2* CIRCLE_CIRCLE(const Collider &A, const Collider &B);

            // Return Point of Collision
            static glm::vec2* AABB_LINE(const glm::vec2& initialPosition, const glm::vec2 &finalPosition, const Collider &A);
            static glm::vec2* CIRCLE_LINE(const glm::vec2& initialPosition, const glm::vec2 &finalPosition, const Collider &A);
            static glm::vec2* LINE_LINE(const glm::vec2& initialA, const glm::vec2 &finalA, const glm::vec2& initialB, const glm::vec2 &finalB);

    };

}
