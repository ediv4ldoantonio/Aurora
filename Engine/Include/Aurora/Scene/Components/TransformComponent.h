#pragma once

#include "Aurora/Scene/Components/Component.h"
#include "Aurora/Math/Transform.h"

namespace Aurora
{

    struct TransformComponent : public Component
    {
        Aurora::Transform Transform;
    };

}