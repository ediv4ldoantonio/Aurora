#include "Aurora/Systems/ScriptSystem.h"
#include "Aurora/Scene/Components/ScriptComponent.h"
#include "Aurora/Scene/Scene.h"

namespace Aurora
{
    void ScriptSystem::OnUpdate(
        Registry &registry,
        float dt)
    {
        auto view = registry.ViewEntities<ScriptComponent>();

        for (auto entity :
             view.GetEntities())
        {
            auto &script =
                entity.GetComponent<ScriptComponent>();

            if (!script.Instance)
            {
                script.Instance =
                    script.InstantiateScript();

                script.Instance->SetEntity(entity);

                script.Instance->OnCreate();
            }
            else
            {
                script.Instance->OnUpdate(dt);
            }
        }
    }
}
