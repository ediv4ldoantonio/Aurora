#include "Aurora/Renderer/SDLGraphicsContext.h"

#include <SDL3/SDL.h>

namespace Aurora
{
    SDLGraphicsContext::SDLGraphicsContext(SDL_Window *window)
        : m_Window(window)
    {
    }

    SDLGraphicsContext::~SDLGraphicsContext() = default;

    void SDLGraphicsContext::Init()
    {
        m_Renderer = SDL_CreateRenderer(m_Window, nullptr);
    }

    void SDLGraphicsContext::BeginFrame()
    {
    }

    void SDLGraphicsContext::EndFrame()
    {
    }

    void *SDLGraphicsContext::GetNativeRenderer() const
    {
        return m_Renderer;
    }

    SDL_Renderer *SDLGraphicsContext::GetRenderer() const
    {
        return m_Renderer;
    }
}
