#pragma once

#include "Aurora/Scene/Components/ScriptComponent.h"
#include "Aurora/Input/Input.h"
#include <Aurora/Core/Logger.h>
#include "Aurora/Scene/Components/TransformComponent.h"

class PlayerMovement : public Aurora::Scriptable
{

public:
    void OnUpdate(float dt) override
    {
        auto &transform =
            m_Entity
                .GetComponent<Aurora::TransformComponent>();

        auto speed = 10000.0f;

        if (
            Aurora::Input::IsKeyPressed(
                Aurora::Key::D))
        {
            transform.LocalTransform.Position.x +=
                speed * dt;
        }

        if (
            Aurora::Input::IsKeyPressed(
                Aurora::Key::A))
        {
            transform.LocalTransform.Position.x +=
                -speed * dt;
        }
    }
};