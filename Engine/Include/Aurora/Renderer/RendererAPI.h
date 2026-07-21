#pragma once

#include "Aurora/Math/Vector2.h"

namespace Aurora
{

    class RendererAPI
    {

    public:
        virtual ~RendererAPI() = default;

        virtual void Init() = 0;

        virtual void BeginFrame() = 0;

        virtual void EndFrame() = 0;

        virtual void DrawRectangle(
            const Vector2 &position,
            const Vector2 &size) = 0;
    };

}