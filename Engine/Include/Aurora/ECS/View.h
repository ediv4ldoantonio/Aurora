#pragma once

#include <vector>

#include "Aurora/Scene/Entity.h"

namespace Aurora
{

    template <typename... Components>
    class View
    {

    public:
        View(Registry *registry)
            : m_Registry(registry)
        {
        }

        std::vector<Entity> GetEntities();

    private:
        template <typename... Required>
        bool HasAllComponents(Entity entity)
        {
            return (
                entity.HasComponent<Required>() && ...);
        }

    private:
        Registry *m_Registry = nullptr;
    };

}
