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

glm::vec2 Collision::point;
glm::vec2 Collision::depth;
glm::vec2 Collision::direction;


void Collision::reset(){
    point = glm::vec2(0.0f);
    depth = glm::vec2(0.0f);
    direction = glm::vec2(0.0f);
}

bool Collision::AABB_AABB(const Collider &A, const Collider &B){
    reset();
    glm::vec2 objectDist = A.getCenter() - B.getCenter();
    glm::vec2 minDist = A.getMinDist() + B.getMinDist();

    glm::vec2 collisionDepth = minDist - glm::vec2(std::abs(objectDist.x), std::abs(objectDist.y));
    if(collisionDepth.x > 0 && collisionDepth.y > 0){

        if(std::max(collisionDepth.x, 0.0f) < std::max(collisionDepth.y, 0.0f)){
            collisionDepth.y = 0.0f;
            if(objectDist.x < 0){collisionDepth.x = -collisionDepth.x;}
        }else{
            collisionDepth.x = 0.0f;
            if(objectDist.y < 0){collisionDepth.y = -collisionDepth.y;}
        }
        depth = collisionDepth;
        direction = glm::normalize(objectDist);
        return true;
    }
    return false;
}
// A BOX, B Circle
bool Collision::AABB_CIRCLE(const Collider &A, const Collider &B, bool reverse){

    float circleRadius = B.getMinDist().x;
    glm::vec2 objectDist = A.getCenter() - B.getCenter();

    glm::vec2 closestPoint;
    closestPoint.x = std::min(std::max(objectDist.x, -A.getMinDist().x), A.getMinDist().x);
    closestPoint.y = std::min(std::max(objectDist.y, -A.getMinDist().y), A.getMinDist().y);

    float dist = glm::length(objectDist - closestPoint);
    float collisionDepth = circleRadius - dist;
    glm::vec2 collision = glm::normalize(closestPoint)*collisionDepth;

    if(collisionDepth > 0){
        if(std::abs(closestPoint.x) > std::abs(closestPoint.y)){
            collision.y = 0.0f;
        }else{
            collision.x = 0.0f;
        }

        if(reverse){
            direction = -glm::normalize(objectDist);
            depth = -collision;
        }else{
            direction = glm::normalize(objectDist);
            depth = collision;
        }
        return true;
    }
    return false;
}

bool Collision::CIRCLE_CIRCLE(const Collider &A, const Collider &B){
    reset();

    glm::vec2 objectDist = A.getCenter() - B.getCenter();
    float minDist = A.getMinDist().x + B.getMinDist().x;

    float dist = glm::length(objectDist);
    float collisionDepth = minDist - dist;

    if(collisionDepth > 0){
        direction = glm::normalize(objectDist);
        depth = direction*collisionDepth;
        return true;
    }
    return false;
}

bool Collision::AABB_LINE(const glm::vec2& initialPosition, const glm::vec2 &finalPosition, const Collider &A){
    reset();
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

         if(p == 0 && q < 0){ return false; }  // Parallel Line
         if(p < 0){
             if(r > t1){ return false; }
             else if(r > t0){ t0 = r; }
         }else if(p > 0){
             if(r < t0){ return false; }
             else if(r < t1){ t1 = r; }
         }
     }
     point = glm::vec2(initialPosition + t0*delta);
     return true;
}
