#pragma once

#include "Aurora/Math/Vector2.h"
#include "Aurora/Scene/Components/SpriteComponent.h"
#include "Aurora/Scene/Components/TransformComponent.h"

namespace Aurora
{

    class RendererAPI
    {

    public:
        virtual ~RendererAPI() = default;

        virtual void Init() = 0;

        virtual void BeginFrame() = 0;

        virtual void EndFrame() = 0;

        virtual void DrawSprite(
            const TransformComponent &,
            const SpriteComponent &) = 0;

        virtual void *GetNativeRenderer() = 0;
    };

}