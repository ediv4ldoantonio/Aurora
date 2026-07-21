#pragma once

#include "Aurora/ECS/Registry.h"

namespace Aurora
{

    class RenderSystem
    {

    public:
        static void Render(
            Registry &registry);
    };

}