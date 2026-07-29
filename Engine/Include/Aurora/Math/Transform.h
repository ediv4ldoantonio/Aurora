#pragma once

#include "Aurora/Math/Vector2.h"

namespace Aurora
{

    class Transform
    {
    public:
        Transform() = default;

        Transform(
            const Vector2 &position,
            float rotation = 0.0f,
            const Vector2 &scale = {1.0f, 1.0f});

    public:
        Vector2 Position;

        float Rotation = 0.0f;

        Vector2 Scale = {1.0f, 1.0f};
    };

}