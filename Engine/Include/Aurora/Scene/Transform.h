#pragma once

#include "Aurora/Math/Vector2.h"

namespace Aurora
{

    struct Transform
    {

        Vector2 Position;

        float Rotation = 0.0f;

        Vector2 Scale =
            Vector2(1.0f, 1.0f);
    };

}