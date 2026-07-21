#pragma once

#include <cstdint>

namespace Aurora
{

    using EntityID = uint32_t;

    class Registry;

    class Entity
    {

    public:
        Entity() = default;

        Entity(
            EntityID id,
            Registry *registry);

        EntityID GetID() const
        {
            return m_ID;
        }

        bool IsValid() const;

        template <typename T, typename... Args>
        T &AddComponent(
            Args &&...args);

        template <typename T>
        T &GetComponent();

        template <typename T>
        bool HasComponent();

    private:
        EntityID m_ID = 0;

        Registry *m_Registry = nullptr;
    };

}

#include "Aurora/Scene/Entity.inl"