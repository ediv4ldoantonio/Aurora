#pragma once

#include <string>
#include <utility>

#include "Component.h"

namespace Aurora
{

    struct NameComponent : public Component
    {
        NameComponent() = default;

        explicit NameComponent(std::string name)
            : Name(std::move(name))
        {
        }

        std::string Name = "Entity";
    };

}