#pragma once

#include "Aurora/Scene/Components/Component.h"
#include "Aurora/Math/Vector2.h"
#include "Aurora/Renderer/Color.h"
#include "Aurora/Renderer/Texture2D.h"

namespace Aurora
{

    struct SpriteComponent : public Component
    {
        Aurora::Color Tint = Color::White;

        std::shared_ptr<Texture2D> Texture;
    };

}