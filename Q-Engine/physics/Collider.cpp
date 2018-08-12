//
//  RectangleCollider.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Collider.hpp"
#include "Collision.hpp"
#include <iostream>

using namespace QEngine;

Collider::Collider(int type, const glm::vec2 &position, const glm::vec2 &size) : type_(type), position_(position), size_(size){}

bool Collider::collides(const Collider &collider) const{
    switch(type_){
        case AABB:
            if(collider.type_ == AABB){
                return Collision::AABB_AABB(*this, collider);
            }
            if(collider.type_ == CIRCLE){
                return Collision::AABB_CIRCLE(*this, collider);
            }
        case CIRCLE:
            if(collider.type_ == CIRCLE){
                return Collision::CIRCLE_CIRCLE(*this, collider);
            }
            if(collider.type_ == AABB){
                return Collision::AABB_CIRCLE(collider, *this, true);
            }
        default:
            return NULL;
    }
}

void Collider::moveCollider(const glm::vec2 &translate){
    position_ += translate;
}
void Collider::setPosition(const glm::vec2 &position){
    position_ = position;
}

glm::vec2 Collider::getCenter() const{

    switch(type_){
        case AABB:
            return position_ + 0.5f*size_;
        case CIRCLE:
            return position_ + size_;
        default:
            return position_;
    }
}
glm::vec2 Collider::getMinDist() const{

    switch(type_){
            case AABB:
                return 0.5f*size_;
            case CIRCLE:
                return size_;
            default:
                return size_;
        }
}
