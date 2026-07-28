#pragma once

#include "Aurora/ECS/System.h"

namespace Aurora
{
    class ScriptSystem : public System
    {

    public:
        void OnUpdate(
            Registry &registry,
            float dt) override;
    };

}