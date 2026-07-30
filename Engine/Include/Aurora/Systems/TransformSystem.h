#pragma once

#include "Aurora/ECS/System.h"
#include "Aurora/Scene/Entity.h"
#include "Aurora/Math/Vector2.h"

namespace Aurora
{
    class TransformSystem : public System
    {
    public:
        void OnUpdate(
            Registry &registry,
            float dt) override;

    private:
        void UpdateEntity(Entity entity);
    };
}