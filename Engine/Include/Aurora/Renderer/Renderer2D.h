#pragma once

#include "Aurora/Math/Vector2.h"

#include <memory>

namespace Aurora
{

    class RendererAPI;

    class Renderer2D
    {

    public:
        static void Init(
            RendererAPI *renderer);

        static void Shutdown();

        static void BeginFrame();

        static void EndFrame();

        static void DrawRectangle(
            const Vector2 &position,
            const Vector2 &size);

    private:
        static RendererAPI *s_Renderer;
    };

}