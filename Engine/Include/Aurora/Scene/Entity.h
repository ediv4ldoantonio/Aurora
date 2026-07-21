#pragma once

#include <cstdint>

namespace Aurora
{

    using EntityID = uint32_t;

    class Scene;

    class Entity
    {

    public:
        Entity() = default;

        Entity(
            EntityID id,
            Scene *scene);

        EntityID GetID() const;

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

        Scene *m_Scene = nullptr;
    };

}
