//
//  Collider.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include <glm/glm.hpp>

// REVISIT Needs Improving.
// Abstract Collider? AABB, Circle
// Make Line Differerent class?
// Friend Classes?

enum {
    AABB,
    CIRCLE
};

namespace QEngine{

    class Collider{

        public:
            Collider(int type, const glm::vec2 &position, const glm::vec2 &size = glm::vec2(0.0f));

            glm::vec2* collides(const Collider &collider) const;

            void moveCollider(const glm::vec2 &translate);
            glm::vec2 getCenter() const;
            glm::vec2 getMinDist() const;

        private:
            glm::vec2 position_; // Top Left
            glm::vec2 size_; // AABB: Width, Heigth. CIRCLE: Radius, Radius.
            int type_;
    };

}
