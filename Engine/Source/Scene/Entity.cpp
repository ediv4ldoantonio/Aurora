#include "Aurora/Scene/Entity.h"

namespace Aurora
{

    Entity::Entity(
        EntityID id,
        Registry *registry)
        : m_ID(id),
          m_Registry(registry)
    {
    }

    EntityID Entity::GetID() const
    {
        return m_ID;
    }

    bool Entity::IsValid() const
    {
        return m_Registry != nullptr;
    }

}