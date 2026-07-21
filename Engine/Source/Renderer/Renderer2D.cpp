#include "Aurora/Renderer/Renderer2D.h"

#include "Renderer2DData.h"

#include <SDL3/SDL.h>

namespace Aurora
{

    static Renderer2DData s_Data;

    void Renderer2D::Init(void *nativeRenderer)
    {
        s_Data.Renderer =
            static_cast<SDL_Renderer *>(nativeRenderer);
    }

    void Renderer2D::Shutdown()
    {
        s_Data.Renderer = nullptr;
    }

    void Renderer2D::BeginFrame()
    {
        SDL_SetRenderDrawColor(
            s_Data.Renderer,
            30,
            30,
            30,
            255);

        SDL_RenderClear(
            s_Data.Renderer);
    }

    void Renderer2D::EndFrame()
    {
        SDL_RenderPresent(
            s_Data.Renderer);
    }

    void Renderer2D::DrawRectangle(
        const Vector2 &position,
        const Vector2 &size)
    {
        SDL_FRect rect;

        rect.x = position.x;
        rect.y = position.y;

        rect.w = size.x;
        rect.h = size.y;

        SDL_SetRenderDrawColor(
            s_Data.Renderer,
            255,
            255,
            255,
            255);

        SDL_RenderFillRect(
            s_Data.Renderer,
            &rect);
    }
}