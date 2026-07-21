#pragma once

#include "Aurora/Events/Event.h"

namespace Aurora
{

    class WindowCloseEvent : public Event
    {

    public:
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(
            EventCategoryApplication)
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

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(
            EventCategoryApplication)
    };

}