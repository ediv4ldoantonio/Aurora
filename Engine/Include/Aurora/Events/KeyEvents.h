#pragma once

#include "Event.h"
#include "Aurora/Input/KeyCodes.h"

namespace Aurora
{

    class KeyPressedEvent : public Event
    {

    public:
        KeyPressedEvent(
            KeyCode keycode)
            : m_KeyCode(keycode)
        {
        }

        KeyCode GetKeyCode() const
        {
            return m_KeyCode;
        }

        EVENT_CLASS_TYPE(KeyPressed)
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    private:
        KeyCode m_KeyCode;
    };

    class KeyReleasedEvent : public Event
    {

    public:
        KeyReleasedEvent(
            KeyCode keycode)
            : m_KeyCode(keycode)
        {
        }

        KeyCode GetKeyCode() const
        {
            return m_KeyCode;
        }

        EVENT_CLASS_TYPE(KeyReleased)
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    private:
        KeyCode m_KeyCode;
    };

}