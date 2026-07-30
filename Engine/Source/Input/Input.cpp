#include "Aurora/Input/Input.h"
#include "Aurora/Input/KeyCodes.h"
#include "Aurora/Events/KeyEvents.h"
#include "Aurora/Events/Event.h"
#include "Aurora/Events/EventDispatcher.h"

#include <cstring>

namespace Aurora
{

    bool Input::s_CurrentKeys[512] = {};
    bool Input::s_PreviousKeys[512] = {};

    bool Input::IsKeyPressed(KeyCode key)
    {
        int index = static_cast<int>(key);

        return s_CurrentKeys[index] &&
               !s_PreviousKeys[index];
    }

    bool Input::IsKeyDown(KeyCode key)
    {
        return s_CurrentKeys[static_cast<int>(key)];
    }

    bool Input::IsKeyReleased(KeyCode key)
    {
        int index = static_cast<int>(key);

        return !s_CurrentKeys[index] &&
               s_PreviousKeys[index];
    }

    void Input::SetKey(
        KeyCode key,
        bool pressed)
    {
        s_CurrentKeys[static_cast<int>(key)] = pressed;
    }

    void Input::Update()
    {
        std::memcpy(
            s_PreviousKeys,
            s_CurrentKeys,
            sizeof(s_CurrentKeys));
    }

    void Input::ProcessEvent(
        Event &event)
    {

        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<KeyPressedEvent>(
            [](KeyPressedEvent &e)
            {
                s_CurrentKeys[(int)e.GetKeyCode()] = true;

                return true;
            });

        dispatcher.Dispatch<KeyReleasedEvent>(
            [](KeyReleasedEvent &e)
            {
                s_CurrentKeys[(int)e.GetKeyCode()] = false;

                return true;
            });
    }

}