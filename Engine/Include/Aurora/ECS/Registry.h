#pragma once

#include <unordered_map>
#include <memory>
#include <typeindex>

#include "Aurora/ECS/ComponentPool.h"

namespace Aurora
{

    class Registry
    {

    public:
        Entity CreateEntity();

        template <typename T, typename... Args>
        T &AddComponent(
            EntityID entity,
            Args &&...args);

        template <typename T>
        T &GetComponent(
            EntityID entity);

        template <typename T>
        bool HasComponent(
            EntityID entity);

    private:
        template <typename T>
        ComponentPool<T> &GetPool();

    private:
        EntityID m_NextEntityID = 1;

        std::vector<EntityID> m_Entities;

        std::unordered_map<
            std::type_index,
            std::unique_ptr<IComponentPool>>
            m_ComponentPools;
    };

}