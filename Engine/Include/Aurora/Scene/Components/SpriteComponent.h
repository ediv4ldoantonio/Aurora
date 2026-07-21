#pragma once

#include "Aurora/Scene/Components/Component.h"
#include "Aurora/Math/Vector2.h"

namespace Aurora
{

    struct SpriteComponent : public Component
    {

        Vector2 Size{50, 50};
    };

}