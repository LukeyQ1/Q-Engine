//
//  ResourceManager.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 24/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Texture.hpp"
#include "IOManager.hpp"

namespace QEngine{

    class ResourceManager{

        public:
            ResourceManager();
            ~ResourceManager();

            void quit();

            bool loadTexture(const std::string& path, ColorRGBA colorKey = {0xFF, 0xFF, 0xFF});

            static Texture* getTexture(const std::string& path);

        private:
            static std::unordered_map<std::string, Texture> textureMap_;

    };

}
