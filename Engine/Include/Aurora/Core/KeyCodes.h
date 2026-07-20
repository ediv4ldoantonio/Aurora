#pragma once

namespace Aurora
{

    enum class Key
    {
        Unknown = 0,

        Space,
        Escape,

        A,
        B,
        C,
        D,

        W,
        S,

        Up,
        Down,
        Left,
        Right
    };

    Key KeyFromSDL(int key);
}