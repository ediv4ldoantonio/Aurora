#include <Aurora/Core/Window.h>
#include <Aurora/Core/Logger.h>
#include <Aurora/Core/Input.h>
#include <Aurora/Renderer/SDLGraphicsContext.h>
#include <SDL3/SDL.h>

namespace Aurora
{
    struct Window::WindowData
    {
        SDL_Window *Window = nullptr;

        bool ShouldClose = false;
    };

    Window::Window(
        const WindowSpecification &specification)
        : m_Specification(specification)
    {

        m_Data = std::make_unique<WindowData>();

        AURORA_LOG_INFO("Initializing SDL video subsystem");
        SDL_Init(
            SDL_INIT_VIDEO);

        m_Data->Window = SDL_CreateWindow(
            specification.Title.c_str(),
            specification.Width,
            specification.Height,
            0);

        if (m_Data->Window)
        {
            AURORA_LOG_INFO("Created window: ", specification.Title, " (", specification.Width, "x", specification.Height, ")");
        }
        else
        {
            AURORA_LOG_ERROR("Failed to create window: ", specification.Title);
        }

        m_GraphicsContext =
            std::make_unique<SDLGraphicsContext>(
                m_Data->Window);

        m_GraphicsContext->Init();
    }

    Window::~Window()
    {
        m_GraphicsContext.reset();

        if (m_Data->Window)
        {
            SDL_DestroyWindow(
                m_Data->Window);
        }
    }

    void Window::PollEvents()
    {
        SDL_Event event;

        while (
            SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
            {
                m_Data->ShouldClose = true;
                AURORA_LOG_INFO("Window quit event received");

                break;
            }

            case SDL_EVENT_KEY_DOWN:
            {
                auto key =
                    KeyFromSDL(event.key.key);

                Input::SetKey(
                    key,
                    true);

                break;
            }

            case SDL_EVENT_KEY_UP:
            {
                auto key =
                    KeyFromSDL(event.key.key);

                Input::SetKey(
                    key,
                    false);

                break;
            }
            }
        }
    }

    bool Window::ShouldClose() const
    {
        return m_Data->ShouldClose;
    }

    GraphicsContext &
    Window::GetGraphicsContext()
    {
        return *m_GraphicsContext;
    }
}