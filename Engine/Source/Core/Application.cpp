#include <Aurora/Core/Application.h>
#include <Aurora/Core/Logger.h>
#include <Aurora/Core/Window.h>
#include <Aurora/Core/Time.h>
#include <Aurora/Core/Input.h>

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
        AURORA_LOG_INFO("Starting application loop");

        while (m_Running)
        {
            Time::Update();

            Input::Update();

            m_Window->PollEvents();

            if (m_Window->ShouldClose())
            {
                AURORA_LOG_INFO("Closing application because the window requested shutdown");
                m_Running = false;
            }

            // Update game layers
            for (auto &layer : m_LayerStack)
            {
                layer->OnUpdate(Time::DeltaTime());
            }

            // Render layers
            for (auto &layer : m_LayerStack)
            {
                layer->OnRender();
            }
        }

        AURORA_LOG_INFO("Application loop exited");
    }

    void Application::Initialize()
    {
        Logger::Initialize();
        Logger::SetLevel(LogLevel::Trace);
        AURORA_LOG_INFO("Starting Aurora application");

        WindowSpecification spec;

        spec.Title =
            "Aurora Sandbox";

        spec.Width = 1280;

        spec.Height = 720;

        m_Window =
            std::make_unique<Window>(
                spec);

        AURORA_LOG_INFO("Created window: ", spec.Title, " (", spec.Width, "x", spec.Height, ")");
    }

    void Application::Shutdown()
    {
        AURORA_LOG_INFO("Shutting down Aurora application");
        Logger::Shutdown();
    }

}