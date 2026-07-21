#pragma once

#include <memory>
#include <string>

#include "Aurora/Renderer/GraphicsContext.h"

namespace Aurora
{
    struct WindowSpecification
    {
        std::string Title = "Aurora";
        int Width = 1280;
        int Height = 720;
    };

    class GraphicsContext;

    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void PollEvents() = 0;

        virtual bool ShouldClose() const = 0;

        virtual GraphicsContext &GetGraphicsContext() = 0;

        static std::unique_ptr<Window> Create(const WindowSpecification &specification = WindowSpecification{});
    };
}