//
//  Body.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Body.hpp"
#include "Physics.h"

using namespace QEngine;

//
// Collisions
//
void Body::addCollider(Collider* collider){
    colliderList_.push_back(collider);
}

bool Body::collides(const Collider &collider) const{
    bool collide = false;
    for(int i = 0; i < colliderList_.size(); i++){
        collide = colliderList_[i]->collides(collider);
        if(collide){
            return collide;
        }
    }
    return false;
}
bool Body::collides(const Body &body) const{
    bool collide = false;
    for(int i = 0; i < colliderList_.size(); i++){
        collide = body.collides(*colliderList_[i]);
        if(collide){
            return collide;
        }
    }
    return false;
}
//
// Movement
//
void Body::updatePhysics(float deltaTime){
    move(velocity_*deltaTime);
    applyGravity(deltaTime);
    applyFriction(deltaTime);
}

void Body::move(const glm::vec2 &translate){
    position_ += translate;
    moveColliders(translate);
}
void Body::setPosition(const glm::vec2 &position){
    position_ = position;
    for(int i = 0; i < colliderList_.size(); i++){
        colliderList_[i]->setPosition(position);
    }
}
void Body::moveColliders(const glm::vec2 &translate){
    for(int i = 0; i < colliderList_.size(); i++){
        colliderList_[i]->moveCollider(translate);
    }
}
//
// Forces
//
void Body::applyForce(const glm::vec2 &force, float deltaTime) {
    if(deltaTime == 0){
        velocity_ += force/mass_;
    }
}
void Body::applyForce(const float &force, const float &angle, float deltaTime) {
    glm::vec2 forceVec = Physics::forceVec(force, angle);
    applyForce(forceVec, deltaTime);
}


void Body::applyFriction(float deltaTime){
    if(velocity_.x != 0 || velocity_.y != 0){ // If Moving
        if(FRICTION_COEFFICIENT < glm::length(velocity_)){ // If would not stop body
            velocity_ -= deltaTime * FRICTION_COEFFICIENT * glm::normalize(velocity_);
        }else{
            velocity_ = glm::vec2(0.0f);
        }
    }
}

void Body::applyGravity(float deltaTime){
    if(GRAVITY != 0.0f && GRAVITY_DIRECTION != glm::vec2(0.0f)){
        velocity_ += GRAVITY*glm::normalize(GRAVITY_DIRECTION);
    }
}


