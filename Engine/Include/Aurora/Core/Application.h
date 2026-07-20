#pragma once

#include <memory>

namespace Aurora
{
    class Window;

    class Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:
        void Initialize();
        void Shutdown();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running;
    };
}