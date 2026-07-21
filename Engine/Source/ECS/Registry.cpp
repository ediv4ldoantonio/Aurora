#include "Aurora/ECS/Registry.h"
#include "Aurora/Scene/Entity.h"

namespace Aurora
{

    Entity Registry::CreateEntity()
    {
        EntityID id = m_NextEntityID++;

        m_Entities.push_back(id);

        return Entity(id, this);
    }

}