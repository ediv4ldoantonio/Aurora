#pragma once

#include "Aurora/Scene/Components/Component.h"
#include "Aurora/Math/Vector2.h"
#include "Aurora/Renderer/Color.h"

namespace Aurora
{

    struct SpriteComponent : public Component
    {
        Aurora::Color Color = Color::White;
    };

}