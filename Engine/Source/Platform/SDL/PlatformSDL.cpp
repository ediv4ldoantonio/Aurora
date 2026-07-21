#include "Aurora/Core/Window.h"
#include "Aurora/Renderer/GraphicsContext.h"
#include "SDLGraphicsContext.h"
#include "SDLWindow.h"

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
}
