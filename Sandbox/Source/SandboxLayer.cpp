#include "SandboxLayer.h"
#include <Aurora/Core/Logger.h>
#include <Aurora/Core/Input.h>
#include <Aurora/Renderer/Renderer2D.h>

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
}

void SandboxLayer::OnRender()
{

    auto position =
        m_Player
            .GetTransform()
            .Position;

    Aurora::Renderer2D::DrawRectangle(
        position,
        {50, 50});
}