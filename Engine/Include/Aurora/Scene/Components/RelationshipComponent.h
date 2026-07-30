#pragma once

#include "Aurora/Scene/Entity.h"

#include <vector>

namespace Aurora
{

    struct RelationshipComponent
    {
        Entity Parent;

        std::vector<Entity> Children;
    };

}