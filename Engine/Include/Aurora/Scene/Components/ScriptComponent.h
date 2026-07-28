#pragma once

#include "Aurora/Scene/Components/Component.h"
#include "Aurora/Scene/Entity.h"

namespace Aurora
{

    class Scriptable
    {

    public:
        virtual ~Scriptable() = default;

        virtual void OnCreate()
        {
        }

        virtual void OnUpdate(
            float deltaTime)
        {
        }

        void SetEntity(Entity entity)
        {
            m_Entity = entity;
        }

    protected:
        Entity m_Entity;
    };

    struct ScriptComponent : public Component
    {
        Scriptable *Instance = nullptr;
    };

}