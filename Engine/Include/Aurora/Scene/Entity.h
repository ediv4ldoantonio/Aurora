#pragma once

#include "Aurora/Scene/Transform.h"

namespace Aurora
{

    class Entity
    {

    public:
        Entity() = default;

        Transform &GetTransform()
        {
            return m_Transform;
        }

    private:
        Transform m_Transform;
    };

}