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

bool Hitscan::collides(Body &body){
    bool collide = false;
    for(int i = 0; i < body.colliderList_.size(); i++ ){
        
        if(body.colliderList_[i]->type_ == AABB){
            collide = Collision::AABB_LINE(initial_, final_, *body.colliderList_[i]);
        }else{
            collide = Collision::CIRCLE_LINE(initial_, final_, *body.colliderList_[i]);
        }
        if(collide){
            return collide;   // check closest collider?
        }
    }
    return false;
}

float Hitscan::dist(glm::vec2& point){
    return glm::length(point - initial_);
}
