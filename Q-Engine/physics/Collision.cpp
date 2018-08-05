//
//  Collision.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 02/08/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Collision.hpp"
#include <iostream>

using namespace QEngine;

glm::vec2* Collision::AABB_AABB(const Collider &A, const Collider &B){
    glm::vec2 objectDist = A.getCenter() - B.getCenter();
    glm::vec2 minDist = A.getMinDist() + B.getMinDist();

    glm::vec2 collisionDepth = minDist - glm::vec2(std::abs(objectDist.x), std::abs(objectDist.y));
    if(collisionDepth.x > 0 && collisionDepth.y > 0){
        glm::vec2* depthVec = new glm::vec2(collisionDepth);

        std::cout << "depth: " << depthVec->x << ", " << depthVec->y << std::endl;
        if(std::max(collisionDepth.x, 0.0f) < std::max(collisionDepth.y, 0.0f)){
            depthVec->y = 0.0f;
            if(objectDist.x < 0){depthVec->x = -depthVec->x;}
        }else{
            depthVec->x = 0.0f;
            if(objectDist.y < 0){depthVec->y = -depthVec->y;}
        }
        return depthVec;
    }
    return NULL;
}

glm::vec2* Collision::CIRCLE_CIRCLE(const Collider &A, const Collider &B){

   glm::vec2 objectDist = A.getCenter() - B.getCenter();
   glm::vec2 minDist = A.getMinDist() + B.getMinDist();

   float dist = glm::length(objectDist);

   float collisionDepth = minDist.x - dist;
   if(collisionDepth > 0){
       glm::vec2* collisionDepthVec = new glm::vec2(glm::normalize(objectDist) * collisionDepth);
       return collisionDepthVec;
   }
   return NULL;
}

glm::vec2* Collision::AABB_LINE(const glm::vec2& initialPosition, const glm::vec2 &finalPosition, const Collider &A){
    // Liang-Barsky Algorithm
    glm::vec2 center = A.getCenter();
    glm::vec2 size = A.getMinDist();

    float edgeLeft = center.x - size.x;
    float edgeRight = center.x + size.x;
    float edgeBottom = center.y - size.y;
    float edgeTop = center.y + size.y;

    glm::vec2 delta = finalPosition - initialPosition;

    float t0 = 0.0f, t1 = 1.0f;
    float p,q,r;

    for(int edge = 0; edge < 4; edge++) {   // Left, Right, Bottom, Top
        if(edge == 0){  p = -delta.x;    q = -(edgeLeft-initialPosition.x);  }
        if(edge == 1){  p = delta.x;     q =  (edgeRight-initialPosition.x); }
        if(edge == 2){  p = -delta.y;    q = -(edgeBottom-initialPosition.y);}
        if(edge == 3){  p = delta.y;     q =  (edgeTop-initialPosition.y);   }
        r = q/p;

        if(p == 0 && q < 0){ return NULL; }  // Parallel Line
        if(p < 0){
            if(r > t1){ return NULL; }
            else if(r > t0){ t0 = r; }
        }else if(p > 0){
            if(r < t0){ return NULL; }
            else if(r < t1){ t1 = r; }
        }
    }
    glm::vec2* intersection = new glm::vec2(initialPosition + t0*delta);
    return intersection;
}
