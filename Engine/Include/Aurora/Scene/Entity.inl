#pragma once

#include <utility>

namespace Aurora
{

    template <typename T, typename... Args>
    T &Entity::AddComponent(
        Args &&...args)
    {

        return m_Scene->template AddComponent<T>(
            m_ID,
            std::forward<Args>(args)...);
    }

    template <typename T>
    T &Entity::GetComponent()
    {

        return m_Scene->template GetComponent<T>(
            m_ID);
    }

    template <typename T>
    bool Entity::HasComponent()
    {

        return m_Scene->template HasComponent<T>(
            m_ID);
    }

}