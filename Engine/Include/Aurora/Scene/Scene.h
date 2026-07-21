#pragma once

#include "Aurora/ECS/Registry.h"
#include "Aurora/ECS/SystemManager.h"

namespace Aurora
{

    class Scene
    {

    public:
        Entity CreateEntity();

        void OnUpdate(
            float deltaTime);

        void OnRender();

    private:
        Registry m_Registry;
        SystemManager m_SystemManager;
    };

}