#pragma once

#include "Aurora/Scene/Components/Component.h"
#include "ScriptableEntity.h"

#include <functional>
#include <memory>

namespace Aurora
{
    struct ScriptComponent : public Component
    {
        std::unique_ptr<ScriptableEntity> Instance;

        std::function<
            std::unique_ptr<ScriptableEntity>()>
            InstantiateScript;

        template <typename T>
        void Bind()
        {
            InstantiateScript =
                []()
            {
                return std::make_unique<T>();
            };
        }
    };

}