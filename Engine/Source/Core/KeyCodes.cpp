#include "Aurora/Core/KeyCodes.h"

#include <SDL3/SDL.h>

namespace Aurora
{

    Key KeyFromSDL(int key)
    {

        switch (key)
        {

        case SDLK_W:
            return Key::W;

        case SDLK_A:
            return Key::A;

        case SDLK_S:
            return Key::S;

        case SDLK_D:
            return Key::D;

        case SDLK_SPACE:
            return Key::Space;

        case SDLK_ESCAPE:
            return Key::Escape;

        default:
            return Key::Unknown;
        }
    }

}