//
//  Hitscan.cpp
//  Q-Test
//
//  Created by Luke Quinlan on 03/08/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Hitscan.hpp"
#include "Collision.hpp"


using namespace QEngine;

Hitscan::Hitscan(const glm::vec2 &initalPosisition, const glm::vec2 &finalPosition) : initial_(initalPosisition), final_(finalPosition){}

glm::vec2* Hitscan::collides(Body &body){
    for( int i = 0; i < body.colliderList_.size(); i++ ){
        glm::vec2* collide = Collision::AABB_LINE(initial_, final_, *body.colliderList_[i]); // Collider type?
        if( collide != NULL){
            return collide;   //Return Closest Collision
        }
    }
    return NULL;
}

float Hitscan::dist(glm::vec2& point){
    return glm::length(point - initial_);
}
