//
//  Camera.cpp
//  Q-Engine
//
//  Created by Luke Quinlan on 25/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#include "Camera.hpp"

using namespace QEngine;

Camera::Camera(){}
Camera::~Camera(){}


glm::vec2 Camera::position_ = glm::vec2(0.0f, 0.0f);
float Camera::scale_ = 1.0f;
int Camera::screenWidth_;
int Camera::screenHeight_;


void Camera::init(int screenWidth, int screenHeight){
    screenWidth_ = screenWidth;
    screenHeight_ = screenHeight;

    position_ = glm::vec2(screenWidth/2, screenHeight/2);
}

glm::vec2 Camera::screenToWorld(glm::vec2 screenCoords){
    screenCoords -= glm::vec2 (screenWidth_/2, screenHeight_/2);  // Center Screen
    screenCoords /= scale_;                                      // Scale
    screenCoords += position_;                                   // Move to Camera
    return screenCoords;
}
void Camera::screenToWorld(int& x, int& y){
    glm::vec2 newCoords(x, y);
    newCoords = screenToWorld(newCoords);
    x = newCoords.x;
    y = newCoords.y;
}

glm::vec2 Camera::worldToScreen(glm::vec2 worldCoords){
    worldCoords -= position_;                                   // Move to Camera
    worldCoords *= scale_;                                      // Scale
    worldCoords += glm::vec2 (screenWidth_/2, screenHeight_/2);  // Center Screen
    return worldCoords;
}
void Camera::worldToScreen(int& x, int& y){
    glm::vec2 newCoords(x, y);
    newCoords = worldToScreen(newCoords);
    x = newCoords.x;
    y = newCoords.y;
}

void Camera::moveCamera(const glm::vec2& translate){
    position_ += translate;
}
void Camera::setPosition(const glm::vec2& newPosition) {
    position_ = newPosition;
}
void Camera::setScale(float scale) {
    scale_ = scale;
}

void Camera::scaleObject(int& w, int& h){
    float newW = w;
    float newH = h;
    newW *= scale_;
    newH *= scale_;
    w = newW;
    h = newH;
}

glm::vec2 Camera::getPosition(){
    return position_;
}
float Camera::getScale(){
    return scale_;
}
