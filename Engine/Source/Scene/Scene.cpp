#include "Aurora/Scene/Scene.h"
#include "Aurora/Renderer/Renderer2D.h"
#include "Aurora/Scene/Components/SpriteComponent.h"
#include "Aurora/Scene/Components/TransformComponent.h"
#include "Aurora/Scene/Components/ScriptComponent.h"
#include <Aurora/Core/Logger.h>
#include "Aurora/Scene/Scene.h"
#include "Aurora/Scene/Entity.h"
#include "Aurora/Systems/RenderSystem.h"
#include "Aurora/Systems/ScriptSystem.h"

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

    Entity Scene::CreateEntity()
    {
        return m_Registry.CreateEntity();
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
}