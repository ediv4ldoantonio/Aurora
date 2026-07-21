#include "Aurora/ECS/Registry.h"

namespace Aurora
{

    Entity Registry::CreateEntity()
    {

        EntityID id =
            m_NextEntityID++;

        m_Entities.push_back(id);

        return Entity(
            id,
            this);
    }

    const std::vector<EntityID> &Registry::GetEntities() const
    {
        return m_Entities;
    }
}