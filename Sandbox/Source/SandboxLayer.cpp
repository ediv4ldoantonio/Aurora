#include "SandboxLayer.h"
#include <Aurora/Core/Logger.h>
#include <Aurora/Input/Input.h>
#include <Aurora/Renderer/Renderer2D.h>
#include <Aurora/Scene/Entity.h>
#include "Aurora/Events/Event.h"

#include <iostream>

void SandboxLayer::OnUpdate(float dt)
{
    m_Scene->OnUpdate(dt);
}

void SandboxLayer::OnRender()
{
    m_Scene->OnRender();
}

void SandboxLayer::OnEvent(
    Aurora::Event &event)
{
}