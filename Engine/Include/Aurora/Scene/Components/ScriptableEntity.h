#pragma once

#include "Aurora/Scene/Entity.h"

namespace Aurora
{

    class ScriptableEntity
    {
    public:
        virtual ~ScriptableEntity() = default;

        virtual void OnCreate() {}

        virtual void OnDestroy() {}

        virtual void OnUpdate(float dt) {}

        Entity GetEntity()
        {
            return m_Entity;
        }

    private:
        friend class ScriptSystem;

        void SetEntity(Entity entity)
        {
            m_Entity = entity;
        }

        Entity m_Entity;
    };
}