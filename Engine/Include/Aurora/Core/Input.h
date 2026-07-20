#pragma once

#include "Aurora/Core/KeyCodes.h"

namespace Aurora
{

    class Input
    {

    public:
        static bool IsKeyPressed(Key key);

        static bool IsKeyDown(Key key);

        static bool IsKeyReleased(Key key);

        static void SetKey(
            Key key,
            bool pressed);

        static void Update();

    private:
        static bool s_CurrentKeys[512];

        static bool s_PreviousKeys[512];
    };

}