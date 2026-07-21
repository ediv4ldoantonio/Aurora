#pragma once

#include "Aurora/Scene/Entity.h"

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>

namespace Aurora
{

    class Scene
    {

    public:
        Scene();

        Entity CreateEntity();

        template <typename T, typename... Args>
        T &AddComponent(
            EntityID id,
            Args &&...args);

        template <typename T>
        T &GetComponent(
            EntityID id);

        template <typename T>
        bool HasComponent(
            EntityID id);

        void OnRender();

        void OnUpdate(
            float deltaTime);

    private:
        EntityID m_NextEntityID = 1;

        std::vector<EntityID> m_Entities;

        std::unordered_map<
            EntityID,
            std::unordered_map<
                std::type_index,
                std::shared_ptr<void>>>
            m_Components;
    };

}
#include "Aurora/Scene/Scene.inl"
#include "Aurora/Scene/Entity.inl"