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
    screenCoords -= glm::vec2 (screenWidth_/2, screenHeight_/2);    // Center Screen
    screenCoords /= scale_;                                         // Scale
    screenCoords += position_;                                      // Move to Camera
    return screenCoords;
}

glm::vec2 Camera::worldToScreen(glm::vec2 worldCoords){
    worldCoords -= position_;                                       // Move to Camera
    worldCoords *= scale_;                                          // Scale
    worldCoords += glm::vec2 (screenWidth_/2, screenHeight_/2);     // Center Screen
    return worldCoords;
}

bool Camera::inView(const glm::vec2& position, const glm::vec2& size){
    return ((position.x >= 0 && position.x <= screenWidth_) && (position.y >= 0 && position.y <= screenHeight_)) ||
    ((position.x + size.x >= 0 && position.x + size.x <= screenWidth_) && (position.y >= 0 && position.y <= screenHeight_)) ||
    ((position.x >= 0 && position.x <= screenWidth_) && (position.y + size.y >= 0 && position.y + size.y <= screenHeight_)) ||
    ((position.x + size.x >= 0 && position.x + size.x <= screenWidth_) && (position.y + size.y >= 0 && position.y  + size.y <= screenHeight_));
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
