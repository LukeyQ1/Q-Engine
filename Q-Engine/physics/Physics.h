//
//  Physics.h
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include <glm/glm.hpp>

#include "Collision.hpp"
#include "Collider.hpp"
#include "Body.hpp"
#include "Hitscan.hpp"

static float PI = 3.14159;

namespace QEngine{

    class Physics{

        public:
            static glm::vec2 forceVec(const float& force, const float& angle){
                float rad = angle*PI/180;
                float accX = force*cos(rad);
                float accY = force*sin(rad);
                return glm::vec2 (accX, accY);
            }

            static glm::vec2 maxVel(const float& maxVelocity, const glm::vec2& velocity){
                if( (maxVelocity*maxVelocity)/glm::dot(velocity, velocity) < 1){
                    return glm::normalize(velocity)*maxVelocity;
                }
                return velocity;
            }

    };

}
