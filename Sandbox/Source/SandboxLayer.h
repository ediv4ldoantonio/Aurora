#pragma once

#include <Aurora/Core/Layer.h>
#include <Aurora/Scene/Entity.h>
#include <Aurora/Renderer/Camera2D.h>
#include <Aurora/Renderer/Renderer2D.h>

class SandboxLayer : public Aurora::Layer
{

public:
    SandboxLayer()
        : Layer("Sandbox")
    {
        Aurora::Renderer2D::SetCamera(
            &m_Camera);
    }

    void OnUpdate(float dt) override;
    void OnRender() override;

private:
    Aurora::Entity m_Player;
    Aurora::Camera2D m_Camera;
};