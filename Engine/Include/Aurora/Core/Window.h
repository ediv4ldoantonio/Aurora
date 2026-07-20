#pragma once

#include <string>

namespace Aurora
{
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

    private:
        WindowSpecification m_Specification;

        struct WindowData;

        WindowData *m_Data = nullptr;

        bool m_ShouldClose = false;
    };
}