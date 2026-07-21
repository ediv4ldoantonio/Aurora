#include "SDLWindow.h"
#include "SDLGraphicsContext.h"
#include "Aurora/Events/ApplicationEvents.h"

#include <Aurora/Input/Input.h>
#include <Aurora/Core/Logger.h>

#include <SDL3/SDL.h>

namespace
{
    Aurora::Key TranslateKeyCode(int sdlKey)
    {
        switch (sdlKey)
        {
        case SDLK_W:
            return Aurora::Key::W;
        case SDLK_A:
            return Aurora::Key::A;
        case SDLK_S:
            return Aurora::Key::S;
        case SDLK_D:
            return Aurora::Key::D;
        case SDLK_SPACE:
            return Aurora::Key::Space;
        case SDLK_ESCAPE:
            return Aurora::Key::Escape;
        default:
            return Aurora::Key::Unknown;
        }
    }
}

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

    GraphicsContext &SDLWindow::GetGraphicsContext()
    {
        return *m_Context;
    }

    void SDLWindow::OnUpdate()
    {

        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
            {
                WindowCloseEvent e;

                m_Specification.EventCallback(e);
            }
            }
        }
    }

    void SDLWindow::SetEventCallback(
        const EventCallbackFn &callback)
    {
        m_Specification.EventCallback = callback;
    }
}