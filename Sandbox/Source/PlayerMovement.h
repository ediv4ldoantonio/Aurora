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
            m_Entity.GetComponent<
                Aurora::TransformComponent>();

        if (
            Aurora::Input::IsKeyPressed(
                Aurora::Key::D) ||
            Aurora::Input::IsKeyPressed(
                Aurora::Key::A))
        {
            transform.Position.x +=
                500.0f * dt;

            AURORA_LOG_INFO(transform.Position.x);
        }
    }
};