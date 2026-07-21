#pragma once

#include "Aurora/ECS/System.h"

namespace Aurora
{

    class RenderSystem : public System
    {

    public:
        void OnRender(
            Registry &registry) override;
    };

}