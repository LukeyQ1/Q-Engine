//
//  IOManager.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 24/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Texture.hpp"
#include "Renderer.hpp"

namespace QEngine {

    class IOManager {

        public:

        static bool loadIMG(Texture& newTexture, const std::string& path, ColorRGBA colorKey = {0xFF,0xFF,0xFF});

        //load music
        //load sound
        //load font
        //load file
    };
}
