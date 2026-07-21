#pragma once

#include "Aurora/ECS/Registry.h"

namespace Aurora
{

    class Scene
    {

    public:
        Scene() = default;

        Entity CreateEntity();

        void OnUpdate(
            float deltaTime);

        void OnRender();

    private:
        Registry m_Registry;
    };

}