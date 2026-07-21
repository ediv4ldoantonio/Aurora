#pragma once

#include "Aurora/Core/Window.h"

#include <memory>

struct SDL_Window;

namespace Aurora
{
    class SDLGraphicsContext;

    class SDLWindow : public Window
    {
    public:
        explicit SDLWindow(const WindowSpecification &specification);

        ~SDLWindow() override;

        void PollEvents() override;

        bool ShouldClose() const override;

        GraphicsContext &GetGraphicsContext() override;

    private:
        WindowSpecification m_Specification;
        SDL_Window *m_Window = nullptr;
        bool m_ShouldClose = false;
        std::unique_ptr<SDLGraphicsContext> m_Context;
    };
}