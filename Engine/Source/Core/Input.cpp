#include "Aurora/Core/Input.h"

namespace Aurora
{

    bool Input::s_Keys[512] = {false};

    bool Input::IsKeyPressed(Key key)
    {
        return s_Keys[static_cast<int>(key)];
    }

    void Input::SetKey(
        Key key,
        bool pressed)
    {
        s_Keys[static_cast<int>(key)] = pressed;
    }
}