#pragma once

#include "Aurora/Core/UUID.h"
#include "Component.h"

namespace Aurora
{

    struct IDComponent : public Component
    {
        IDComponent() = default;

        explicit IDComponent(UUID id)
            : ID(id)
        {
        }

        UUID ID;
    };

}