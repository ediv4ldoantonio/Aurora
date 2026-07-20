#include <Aurora/Core/Application.h>
#include <Aurora/Core/Window.h>

namespace Aurora
{
    Application::Application()
        : m_Running(true)
    {
        Initialize();
    }

    Application::~Application()
    {
        Shutdown();
    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->PollEvents();

            if (m_Window->ShouldClose())
                m_Running = false;
        }
    }

    void Application::Initialize()
    {

        WindowSpecification spec;

        spec.Title =
            "Aurora Sandbox";

        spec.Width = 1280;

        spec.Height = 720;

        m_Window =
            std::make_unique<Window>(
                spec);
    }

    void Application::Shutdown()
    {
    }
}