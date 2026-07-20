#pragma once

#include <Aurora/Core/Layer.h>

class SandboxLayer : public Aurora::Layer
{

public:
    SandboxLayer()
        : Layer("Sandbox")
    {
    }

    void OnUpdate(float dt) override;
};