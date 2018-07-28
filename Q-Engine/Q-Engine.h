//
//  Q-Engine.h
//  Q-Engine
//
//  Created by Luke Quinlan on 21/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"

#include "Window.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"

#include "InputManager.hpp"
#include "EventManager.hpp"
#include "IOManager.hpp"
#include "ResourceManager.hpp"
#include "AudioManager.hpp"

#include "Camera.hpp"
#include "Sprite.hpp"
#include "spriteGroup.hpp"

#include "Basics.hpp"
#include "Timer.hpp"

#include "physics/physics.h"

using namespace QEngine;

bool init();

void quit();
