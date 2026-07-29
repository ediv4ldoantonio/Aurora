#include "SDLRendererAPI.h"
#include "SDLTexture2D.h"
#include "Aurora/Core/Logger.h"

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

    void SDLRendererAPI::DrawSprite(
        const TransformComponent &transform,
        const SpriteComponent &sprite)
    {
        SDL_FRect rect;

        rect.x = transform.Transform.Position.x;
        rect.y = transform.Transform.Position.y;

        rect.w = transform.Transform.Scale.x;
        rect.h = transform.Transform.Scale.y;

        if (sprite.Texture)
        {
            auto texture =
                static_cast<SDLTexture2D *>(
                    sprite.Texture.get());

            SDL_Texture *native =
                texture->GetNativeTexture();

            SDL_SetTextureColorMod(
                native,
                sprite.Tint.R,
                sprite.Tint.G,
                sprite.Tint.B);

            SDL_SetTextureAlphaMod(
                native,
                sprite.Tint.A);

            SDL_RenderTexture(
                m_Renderer,
                native,
                nullptr,
                &rect);
        }
        else
        {

            SDL_SetRenderDrawColor(
                m_Renderer,
                sprite.Tint.R,
                sprite.Tint.G,
                sprite.Tint.B,
                sprite.Tint.A);

            SDL_RenderFillRect(
                m_Renderer,
                &rect);
        }
    }

    void *SDLRendererAPI::GetNativeRenderer()
    {
        return m_Renderer;
    }
}