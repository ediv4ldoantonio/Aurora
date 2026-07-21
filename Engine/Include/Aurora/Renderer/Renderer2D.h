#pragma once

#include "Aurora/Math/Vector2.h"

namespace Aurora
{
    class GraphicsContext;

    class Renderer2D
    {
    public:
        static void Init(GraphicsContext &graphicsContext);

        static void Shutdown();

        static void BeginFrame();

        static void EndFrame();

        static void DrawRectangle(
            const Vector2 &position,
            const Vector2 &size);
    };

}