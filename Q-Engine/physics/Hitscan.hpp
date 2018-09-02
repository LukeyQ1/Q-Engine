//
//  Hitscan.hpp
//  Q-Engine
//
//  Created by Luke Quinlan on 03/08/2018.
//  Copyright © 2018 Luke Quinlan. All rights reserved.
//

#pragma once

#include <glm/glm.hpp>
#include "Collider.hpp"
#include "Body.hpp"

namespace QEngine{

    class Hitscan{

    public:
        Hitscan(const glm::vec2 &initalPosisition, const glm::vec2 &finalPosition);

        bool collides(Body &body);

        float dist(glm::vec2& point);

    protected:
        glm::vec2 initial_;
        glm::vec2 final_;
    };

}
