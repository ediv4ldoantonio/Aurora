#pragma once

#include "Aurora/Core/KeyCodes.h"

namespace Aurora
{

    class Input
    {

    public:
        static bool IsKeyPressed(Key key);

        static void SetKey(
            Key key,
            bool pressed);

    private:
        static bool s_Keys[512];
    };

}