//
//  FontManager.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 24/07/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include "Q_stdinc.h"
#include "Font.hpp"
#include "IOManager.hpp"

namespace QEngine{

    class FontManager{

    public:
        FontManager();
        ~FontManager();

        void quit();

        bool loadFont(const std::string& path, int fontSize = 18, ColorRGBA fontColor = {0xFF, 0xFF, 0xFF});

        static Font* getFont(const std::string& path);

    private:
        static std::unordered_map<std::string, Font> fontMap_;
    };

}
