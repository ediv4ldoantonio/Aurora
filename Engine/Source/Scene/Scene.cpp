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

        EntityID id =
            m_NextEntityID++;

        m_Entities.push_back(id);

        return Entity(
            id,
            this);
    }

    void Scene::OnUpdate(
        float deltaTime)
    {

        for (auto entityID : m_Entities)
        {

            Entity entity(
                entityID,
                this);

            auto &scriptComponent =
                entity.GetComponent<ScriptComponent>();

            if (scriptComponent.Instance)
            {

                scriptComponent.Instance->SetEntity(
                    entity);

                scriptComponent.Instance->OnUpdate(
                    deltaTime);
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

                AURORA_LOG_INFO(transform.Position.x, transform.Position.y);

                Renderer2D::DrawRectangle(

                    transform.Position,

                    sprite.Size

                );
            }
        }
    }
}