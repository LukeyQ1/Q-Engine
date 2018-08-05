//
//  Body.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Body.hpp"

using namespace QEngine;

void Body::addCollider(Collider* collider){
    colliderList_.push_back(collider);
}

glm::vec2* Body::collides(const Collider &collider) const{
    for(int i = 0; i < colliderList_.size(); i++){
        glm::vec2* collide = colliderList_[i]->collides(collider);
        if( collide != NULL){
            return collide;
        }
    }
    return NULL;
}

glm::vec2* Body::collides(const Body &body) const{
    for(int i = 0; i < colliderList_.size(); i++){
        glm::vec2* collide = body.collides(*colliderList_[i]);
        if( collide != NULL){
            return collide;
        }
    }
    return NULL;
}

void Body::moveColliders(const glm::vec2 &translate){
    for(int i = 0; i < colliderList_.size(); i++){
        colliderList_[i]->moveCollider(translate);
    }
}
