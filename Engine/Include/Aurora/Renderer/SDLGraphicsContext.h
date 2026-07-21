#pragma once

#include "Aurora/Renderer/GraphicsContext.h"

struct SDL_Window;
struct SDL_Renderer;

namespace Aurora
{

    class SDLGraphicsContext
        : public GraphicsContext
    {
    public:
        explicit SDLGraphicsContext(
            SDL_Window *window);

        ~SDLGraphicsContext() override;

        void Init() override;

        void BeginFrame() override;

        void EndFrame() override;

        void *GetNativeRenderer() const override;

        SDL_Renderer *GetRenderer() const;

    private:
        SDL_Window *m_Window = nullptr;

        SDL_Renderer *m_Renderer = nullptr;
    };

}