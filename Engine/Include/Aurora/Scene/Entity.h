#pragma once

#include <cstdint>
#include <unordered_map>
#include <typeindex>
#include <memory>

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
            Scene *scene)
            : m_ID(id),
              m_Scene(scene)
        {
        }

        template <typename T, typename... Args>
        T &AddComponent(
            Args &&...args)
        {

            auto component =
                std::make_shared<T>(
                    std::forward<Args>(args)...);

            m_Components[std::type_index(typeid(T))] =
                component;

            return *component;
        }

        template <typename T>
        T &GetComponent()
        {

            return *std::static_pointer_cast<T>(
                m_Components[std::type_index(typeid(T))]);
        }

        template <typename T>
        bool HasComponent()
        {

            return m_Components.contains(
                std::type_index(typeid(T)));
        }

    private:
        EntityID m_ID = 0;

        Scene *m_Scene = nullptr;

        std::unordered_map<
            std::type_index,
            std::shared_ptr<void>>
            m_Components;
    };

}