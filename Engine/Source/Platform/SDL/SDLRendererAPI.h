#pragma once

#include "Aurora/Renderer/RendererAPI.h"
#include "Aurora/Scene/Components/SpriteComponent.h"
#include "Aurora/Scene/Components/TransformComponent.h"

struct SDL_Renderer;

namespace Aurora
{

    class SDLRendererAPI : public RendererAPI
    {

    public:
        explicit SDLRendererAPI(
            SDL_Renderer *renderer);

        void Init() override;

        void BeginFrame() override;

        void EndFrame() override;

        void DrawRectangle(
            const TransformComponent &transform,
            const SpriteComponent &sprite) override;

    private:
        SDL_Renderer *m_Renderer;
    };

}