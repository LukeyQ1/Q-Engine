//
//  SpriteGroup.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 27/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Sprite.hpp"

namespace QEngine{

    class SpriteGroup{

        public:
            SpriteGroup();
            ~SpriteGroup();

            Sprite getSprite(int name);
            void addSprite(Sprite newSprite, int name);

        private:
        std::unordered_map<int, Sprite> spriteList_;

    };
}
