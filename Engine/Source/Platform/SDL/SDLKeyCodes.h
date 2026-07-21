#pragma once

#include "Aurora/Input/KeyCodes.h"
#include <SDL3/SDL.h>

namespace Aurora
{

    KeyCode SDLKeyToAurora(
        SDL_Keycode key);

}