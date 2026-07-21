#include "SDLRendererAPI.h"

#include <SDL3/SDL.h>

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
        const Vector2 &position,
        const Vector2 &size)
    {

        SDL_FRect rectangle;

        rectangle.x = position.x;

        rectangle.y = position.y;

        rectangle.w = size.x;

        rectangle.h = size.y;

        SDL_SetRenderDrawColor(
            m_Renderer,
            255,
            255,
            255,
            255);

        SDL_RenderFillRect(
            m_Renderer,
            &rectangle);
    }

}