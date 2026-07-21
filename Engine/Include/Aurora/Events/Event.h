#pragma once

#include <string>

namespace Aurora
{

    enum class EventType
    {

        None = 0,

        WindowClose,
        WindowResize,

        KeyPressed,
        KeyReleased,

        MouseButtonPressed,
        MouseButtonReleased

    };

    class Event
    {

    public:
        virtual ~Event() = default;

        virtual EventType GetEventType() const = 0;

        virtual const char *GetName() const = 0;

        bool Handled = false;
    };

}