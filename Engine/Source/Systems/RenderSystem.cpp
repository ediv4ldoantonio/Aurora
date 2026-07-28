#include "Aurora/Systems/RenderSystem.h"
#include "Aurora/Scene/Components/TransformComponent.h"
#include "Aurora/Scene/Components/SpriteComponent.h"
#include "Aurora/Renderer/Renderer2D.h"
#include "Aurora/ECS/Registry.h"
#include <Aurora/Core/Logger.h>

namespace Aurora
{

    void RenderSystem::OnRender(
        Registry &registry)
    {

        auto view =
            registry.ViewEntities<
                TransformComponent,
                SpriteComponent>();

        for (auto entity :
             view.GetEntities())
        {
            auto &transform =
                entity.GetComponent<TransformComponent>();

            auto &sprite =
                entity.GetComponent<SpriteComponent>();

            Renderer2D::DrawRectangle(
                transform,
                sprite);
        }
    }

}