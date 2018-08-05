//
//  Body.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Collider.hpp"
#include <vector>

namespace QEngine{

    class Body{

        public:

        friend class Hitscan;

            void addCollider(Collider* collider);
            void moveColliders(const glm::vec2 &translate);

            glm::vec2* collides(const Collider& collider) const;        // Body Must delete pointer after use
            glm::vec2* collides(const Body& body) const;

        protected:
            std::vector<Collider*> colliderList_;                       // Needs to be deleted
    };

}
