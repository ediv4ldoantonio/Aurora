#pragma once

#include "Aurora/Renderer/RendererAPI.h"

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
            const Vector2 &position,
            const Vector2 &size) override;

    private:
        SDL_Renderer *m_Renderer;
    };

}