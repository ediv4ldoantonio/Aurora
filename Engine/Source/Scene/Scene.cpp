#include "Aurora/Scene/Scene.h"
#include "Aurora/Renderer/Renderer2D.h"
#include "Aurora/Scene/Components/SpriteComponent.h"
#include "Aurora/Scene/Components/TransformComponent.h"
#include "Aurora/Scene/Components/ScriptComponent.h"
#include <Aurora/Core/Logger.h>
#include "Aurora/Scene/Scene.h"
#include "Aurora/Scene/Entity.h"

namespace Aurora
{
    using EntityID = uint32_t;

    Scene::Scene()
    {
    }

    Entity Scene::CreateEntity()
    {

        return m_Registry.CreateEntity();
    }

    void Scene::OnUpdate(
        float deltaTime)
    {

        for (auto id : m_Registry.GetEntities())
        {

            Entity entity(
                id,
                &m_Registry);

            if (
                entity.HasComponent<ScriptComponent>())
            {

                auto &script =
                    entity.GetComponent<
                        ScriptComponent>();

                if (script.Instance)
                {
                    script.Instance->OnUpdate(
                        deltaTime);
                }
            }
        }
    }

    void Scene::OnRender()
    {

        for (auto entityID : m_Entities)
        {

            Entity entity(
                entityID,
                this);

            if (
                entity.HasComponent<TransformComponent>() &&
                entity.HasComponent<SpriteComponent>())
            {

                auto &transform =
                    entity.GetComponent<TransformComponent>();

                auto &sprite =
                    entity.GetComponent<SpriteComponent>();

                Renderer2D::DrawRectangle(

                    transform.Position,

                    sprite.Size

                );
            }
        }
    }
}