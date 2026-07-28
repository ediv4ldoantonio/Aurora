#include "Aurora/Core/Window.h"
#include "Aurora/Renderer/GraphicsContext.h"
#include "Aurora/Renderer/Texture2D.h"
#include "SDLGraphicsContext.h"
#include "SDLWindow.h"
#include "SDLTexture2D.h"

namespace Aurora
{
    std::unique_ptr<Window> Window::Create(const WindowSpecification &specification)
    {
        return std::make_unique<SDLWindow>(specification);
    }

    std::unique_ptr<GraphicsContext> GraphicsContext::Create(void *nativeWindow)
    {
        return std::make_unique<SDLGraphicsContext>(static_cast<SDL_Window *>(nativeWindow));
    }

    std::shared_ptr<Texture2D>
    Texture2D::Create(
        const std::string &path)
    {
        return std::make_shared<SDLTexture2D>(path);
    }
}
