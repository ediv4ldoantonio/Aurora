#include "SDLRendererAPI.h"

#include <SDL3/SDL.h>

#include <Aurora/Core/Logger.h>

namespace Aurora
{

    SDLRendererAPI::SDLRendererAPI(
        SDL_Renderer *renderer)
        : m_Renderer(renderer)
    {
    }

    void SDLRendererAPI::Init()
    {
    }

    void SDLRendererAPI::BeginFrame()
    {
        SDL_SetRenderDrawColor(
            m_Renderer,
            20,
            20,
            20,
            255);

        SDL_RenderClear(
            m_Renderer);
    }

    void SDLRendererAPI::EndFrame()
    {
        SDL_RenderPresent(
            m_Renderer);
    }

    void SDLRendererAPI::DrawRectangle(
        const TransformComponent &transform,
        const SpriteComponent &sprite)
    {
        SDL_FRect rect;

        rect.x = transform.Position.x;
        rect.y = transform.Position.y;

        rect.w = transform.Scale.x;
        rect.h = transform.Scale.y;

        SDL_SetRenderDrawColor(
            m_Renderer,
            sprite.Color.R,
            sprite.Color.G,
            sprite.Color.B,
            sprite.Color.A);

        SDL_RenderFillRect(
            m_Renderer,
            &rect);
    }

}