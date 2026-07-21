#pragma once

#include "Aurora/Events/Event.h"

namespace Aurora
{

    class WindowCloseEvent : public Event
    {

    public:
        EventType GetEventType() const override
        {
            return EventType::WindowClose;
        }

        const char *GetName() const override
        {
            return "WindowClose";
        }
    };

    class WindowResizeEvent : public Event
    {

    public:
        WindowResizeEvent(
            unsigned int width,
            unsigned int height)
            : Width(width),
              Height(height)
        {
        }

        unsigned int Width;
        unsigned int Height;

        EventType GetEventType() const override
        {
            return EventType::WindowResize;
        }

        const char *GetName() const override
        {
            return "WindowResize";
        }
    };

}