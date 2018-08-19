//
//  core.h
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
#include "FontManager.hpp"

#include "Camera.hpp"
#include "Timer.hpp"
#include "MainGame.hpp"

using namespace QEngine;

bool init();

void quit();
