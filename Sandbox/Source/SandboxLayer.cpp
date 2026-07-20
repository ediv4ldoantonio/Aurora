#include "SandboxLayer.h"
#include <Aurora/Core/Logger.h>
#include <Aurora/Core/Input.h>

#include <iostream>

void SandboxLayer::OnUpdate(float dt)
{

    if (
        Aurora::Input::IsKeyPressed(
            Aurora::Key::W))
    {
        AURORA_LOG_INFO("Moving forward");
    }
}