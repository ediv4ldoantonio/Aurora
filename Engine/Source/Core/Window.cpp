#include "Aurora/Core/Window.h"
#include <SDL3/SDL.h>

namespace Aurora
{
    struct Window::WindowData
    {
        SDL_Window *Handle = nullptr;

        bool ShouldClose = false;
    };

    Window::Window(
        const WindowSpecification &specification)
        : m_Specification(specification)
    {

        m_Data = new WindowData();

        SDL_Init(
            SDL_INIT_VIDEO);

        m_Data->Handle = SDL_CreateWindow(
            specification.Title.c_str(),
            specification.Width,
            specification.Height,
            0);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(
            m_Data->Handle);

        SDL_Quit();

        delete m_Data;
    }

    void Window::PollEvents()
    {
        SDL_Event event;

        while (
            SDL_PollEvent(&event))
        {

            if (
                event.type ==
                SDL_EVENT_QUIT)
            {
                m_ShouldClose = true;
            }
        }
    }

    bool Window::ShouldClose() const
    {
        return m_Data->ShouldClose;
    }
}