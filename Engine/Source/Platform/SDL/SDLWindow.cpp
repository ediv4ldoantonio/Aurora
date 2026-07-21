#include "SDLWindow.h"
#include "SDLGraphicsContext.h"

#include <Aurora/Core/Input.h>
#include <Aurora/Core/Logger.h>

#include <SDL3/SDL.h>

namespace Aurora
{
    SDLWindow::SDLWindow(const WindowSpecification &specification)
        : m_Specification(specification)
    {
        AURORA_LOG_INFO("Initializing SDL video subsystem");
        SDL_Init(SDL_INIT_VIDEO);

        m_Window = SDL_CreateWindow(
            m_Specification.Title.c_str(),
            m_Specification.Width,
            m_Specification.Height,
            SDL_WINDOW_RESIZABLE);

        if (m_Window)
        {
            AURORA_LOG_INFO("Created window: ", m_Specification.Title, " (", m_Specification.Width, "x", m_Specification.Height, ")");
        }
        else
        {
            AURORA_LOG_ERROR("Failed to create window: ", m_Specification.Title);
        }

        m_Context = std::make_unique<SDLGraphicsContext>(m_Window);
        m_Context->Init();
    }

    SDLWindow::~SDLWindow()
    {
        m_Context.reset();

        if (m_Window)
        {
            SDL_DestroyWindow(m_Window);
        }

        SDL_Quit();
    }

    void SDLWindow::PollEvents()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
            {
                m_ShouldClose = true;
                AURORA_LOG_INFO("Window quit event received");
                break;
            }

            case SDL_EVENT_KEY_DOWN:
            {
                auto key = KeyFromSDL(event.key.key);
                Input::SetKey(key, true);
                break;
            }

            case SDL_EVENT_KEY_UP:
            {
                auto key = KeyFromSDL(event.key.key);
                Input::SetKey(key, false);
                break;
            }
            }
        }
    }

    bool SDLWindow::ShouldClose() const
    {
        return m_ShouldClose;
    }

    GraphicsContext &SDLWindow::GetGraphicsContext()
    {
        return *m_Context;
    }
}
