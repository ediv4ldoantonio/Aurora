#pragma once

#include <Aurora/Core/Layer.h>
#include <Aurora/Scene/Entity.h>

class SandboxLayer : public Aurora::Layer
{

public:
    SandboxLayer()
        : Layer("Sandbox")
    {
    }

    void OnUpdate(float dt) override;

private:
    Aurora::Entity m_Player;
};