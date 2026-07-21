#pragma once

#include "Aurora/Renderer/GraphicsContext.h"

#include <memory>

struct SDL_Window;
struct SDL_Renderer;

namespace Aurora
{

    class SDLRendererAPI;

    class SDLGraphicsContext
        : public GraphicsContext
    {

    public:
        SDLGraphicsContext(
            SDL_Window *window);

        ~SDLGraphicsContext() override;

        void Init() override;

        RendererAPI *
        GetRendererAPI() override;

    private:
        SDL_Window *m_Window = nullptr;

        SDL_Renderer *m_Renderer = nullptr;

        std::unique_ptr<SDLRendererAPI>
            m_RendererAPI;
    };

}