#pragma once

#include "Aurora/Scene/Scene.h"

namespace Aurora
{

    template <typename T, typename... Args>
    T &Scene::AddComponent(
        EntityID id,
        Args &&...args)
    {

        auto component =
            std::make_shared<T>(
                std::forward<Args>(args)...);

        m_Components[id]
                    [std::type_index(typeid(T))] =
                        component;

        return *component;
    }

    template <typename T>
    T &Scene::GetComponent(
        EntityID id)
    {

        return *std::static_pointer_cast<T>(
            m_Components[id]
                        [std::type_index(typeid(T))]);
    }

    template <typename T>
    bool Scene::HasComponent(
        EntityID id)
    {

        auto entityIt =
            m_Components.find(id);

        if (entityIt == m_Components.end())
        {
            return false;
        }

        return entityIt->second.contains(
            std::type_index(typeid(T)));
    }
}