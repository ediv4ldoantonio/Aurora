#pragma once

#include "Aurora/Scene/Entity.h"

#include <vector>

namespace Aurora
{

    class Scene
    {

    public:
        Scene();

        Entity CreateEntity();

        void DestroyEntity(
            Entity entity);

    private:
        EntityID m_NextEntityID = 1;
    };

}