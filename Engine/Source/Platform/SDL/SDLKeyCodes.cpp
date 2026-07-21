#include "SDLKeyCodes.h"

namespace Aurora
{

    KeyCode SDLKeyToAurora(
        SDL_Keycode key)
    {

        switch (key)
        {

        case SDLK_A:
            return Key::A;

        case SDLK_B:
            return Key::B;

        case SDLK_C:
            return Key::C;

        case SDLK_D:
            return Key::D;

        case SDLK_E:
            return Key::E;

        case SDLK_F:
            return Key::F;

        case SDLK_SPACE:
            return Key::Space;

        case SDLK_ESCAPE:
            return Key::Escape;

        case SDLK_RETURN:
            return Key::Enter;

        case SDLK_UP:
            return Key::Up;

        case SDLK_DOWN:
            return Key::Down;

        case SDLK_LEFT:
            return Key::Left;

        case SDLK_RIGHT:
            return Key::Right;

        default:
            return Key::Unknown;
        }
    }

}