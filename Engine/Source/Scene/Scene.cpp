#include "Aurora/Scene/Scene.h"
#include "Aurora/Renderer/Renderer2D.h"
#include "Aurora/Scene/Components/SpriteComponent.h"
#include "Aurora/Scene/Components/TransformComponent.h"
#include "Aurora/Scene/Components/ScriptComponent.h"
#include "Aurora/Scene/Components/IDComponent.h"
#include "Aurora/Scene/Components/NameComponent.h"
#include "Aurora/Scene/Components/RelationshipComponent.h"
#include <Aurora/Core/Logger.h>
#include "Aurora/Scene/Scene.h"
#include "Aurora/Scene/Entity.h"
#include "Aurora/Systems/RenderSystem.h"
#include "Aurora/Systems/ScriptSystem.h"

#include <algorithm>

namespace Aurora
{
    using EntityID = uint32_t;

    Scene::Scene()
    {

        m_SystemManager
            .AddSystem<RenderSystem>();

        m_SystemManager
            .AddSystem<ScriptSystem>();
    }

    Entity Scene::CreateEntity(const std::string &name)
    {
        Entity entity = m_Registry.CreateEntity();

        entity.AddComponent<IDComponent>();
        entity.AddComponent<NameComponent>(name);
        entity.AddComponent<TransformComponent>();
        entity.AddComponent<RelationshipComponent>();

        return entity;
    }

    void Scene::OnUpdate(
        float deltaTime)
    {

        m_SystemManager.Update(
            m_Registry,
            deltaTime);
    }

    void Scene::OnRender()
    {
        m_SystemManager.Render(
            m_Registry);
    }

    void Scene::SetParent(
        Entity child,
        Entity parent)
    {
        RemoveParent(child);

        auto &childRelationship =
            child.GetComponent<RelationshipComponent>();

        auto &parentRelationship =
            parent.GetComponent<RelationshipComponent>();

        childRelationship.Parent = parent;

        parentRelationship.Children.push_back(child);
    }

    void Scene::RemoveParent(
        Entity child)
    {
        auto &childRelationship =
            child.GetComponent<RelationshipComponent>();

        if (!childRelationship.Parent)
            return;

        auto &parentRelationship =
            childRelationship.Parent
                .GetComponent<RelationshipComponent>();

        auto &children =
            parentRelationship.Children;

        children.erase(
            std::remove(
                children.begin(),
                children.end(),
                child),
            children.end());

        childRelationship.Parent = {};
    }
}