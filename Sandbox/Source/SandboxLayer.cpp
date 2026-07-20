#include "SandboxLayer.h"
#include <Aurora/Core/Logger.h>
#include <Aurora/Core/Input.h>

#include <iostream>

void SandboxLayer::OnUpdate(float dt)
{

    auto &position =
        m_Player.GetTransform().Position;

    float speed = 200.0f;

    if (
        Aurora::Input::IsKeyDown(
            Aurora::Key::D))
    {
        position.x += speed * dt;
    }

    if (
        Aurora::Input::IsKeyDown(
            Aurora::Key::A))
    {
        position.x -= speed * dt;
    }

    if (
        Aurora::Input::IsKeyDown(
            Aurora::Key::W))
    {
        position.y += speed * dt;
    }

    if (
        Aurora::Input::IsKeyDown(
            Aurora::Key::S))
    {
        position.y -= speed * dt;
    }

    AURORA_LOG_INFO(
        "Player Position: {}, {}",
        position.x,
        position.y);
}