#include "Aurora/Input/Input.h"

#include <cstring>

namespace Aurora
{

    bool Input::s_CurrentKeys[512] = {};
    bool Input::s_PreviousKeys[512] = {};

    bool Input::IsKeyPressed(Key key)
    {
        int index = static_cast<int>(key);

        return s_CurrentKeys[index] &&
               !s_PreviousKeys[index];
    }

    bool Input::IsKeyDown(Key key)
    {
        return s_CurrentKeys[static_cast<int>(key)];
    }

    bool Input::IsKeyReleased(Key key)
    {
        int index = static_cast<int>(key);

        return !s_CurrentKeys[index] &&
               s_PreviousKeys[index];
    }

    void Input::SetKey(
        Key key,
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

}