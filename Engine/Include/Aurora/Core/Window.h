#pragma once

#include <string>
#include <memory>

struct SDL_Window;
struct SDL_Renderer;

namespace Aurora
{
    class GraphicsContext;

    struct WindowSpecification
    {
        std::string Title = "Aurora";
        int Width = 1280;
        int Height = 720;
    };

    class Window
    {
    public:
        explicit Window(const WindowSpecification &specification);
        ~Window();

        void PollEvents();

        bool ShouldClose() const;

        GraphicsContext &GetGraphicsContext();

    private:
        struct WindowData;
        WindowSpecification m_Specification;

        std::unique_ptr<WindowData> m_Data;
        std::unique_ptr<GraphicsContext> m_GraphicsContext;
    };
}