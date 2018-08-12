//
//  Body.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Collider.hpp"
#include <vector>

namespace QEngine{

    class Body{

        public:

            float FRICTION_COEFFICIENT = 30.0f;

            // Move to different file
            float GRAVITY = 3.0f;
            glm::vec2 GRAVITY_DIRECTION = glm::vec2(0.0f); // Normal to Screen

            friend class Hitscan;

            void move(const glm::vec2 &translate);
            void setPosition(const glm::vec2 &position);
            void updatePhysics(float deltaTime);

            bool collides(const Collider& collider) const;
            bool collides(const Body& body) const;

            void applyForce(const glm::vec2& force, float deltaTime = 0);
            void applyForce(const float& force, const float& angle, float deltaTime = 0);

        protected:
            glm::vec2 position_;
            glm::vec2 velocity_ = glm::vec2(0.0f);

            float mass_ = 1.0f;
        
            void addCollider(Collider* collider);

        private:
            std::vector<Collider*> colliderList_;                       // Needs to be deleted

            void moveColliders(const glm::vec2 &translate);
            void applyFriction(float deltaTime);
            void applyGravity(float deltaTime);
    };

}
