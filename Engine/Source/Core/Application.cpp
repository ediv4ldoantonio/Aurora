#include <Aurora/Core/Application.h>
#include <Aurora/Core/Window.h>
#include <Aurora/Core/Time.h>
#include <chrono>

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

            UpdateTime();

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

    void Application::UpdateTime()
    {
        using namespace std::chrono;

        static auto lastTime =
            high_resolution_clock::now();

        auto currentTime =
            high_resolution_clock::now();

        float delta =
            duration<float>(
                currentTime - lastTime)
                .count();

        Time::s_DeltaTime = delta;

        lastTime = currentTime;
    }
}