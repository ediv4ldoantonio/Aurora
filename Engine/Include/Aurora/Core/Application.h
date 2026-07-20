#pragma once

#include "Aurora/Core/LayerStack.h"
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

        void PushLayer(
            std::unique_ptr<Layer> layer)
        {
            m_LayerStack.PushLayer(
                std::move(layer));
        }

    private:
        void Initialize();
        void Shutdown();
        void UpdateTime();

    private:
        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
        bool m_Running;
    };
}