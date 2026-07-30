#pragma once

#include <Aurora/Core/Layer.h>
#include <Aurora/Scene/Entity.h>
#include <Aurora/Scene/Scene.h>
#include <Aurora/Scene/Components/SpriteComponent.h>
#include <Aurora/Scene/Components/TransformComponent.h>
#include <Aurora/Scene/Components/NameComponent.h>
#include <Aurora/Renderer/Camera2D.h>
#include <Aurora/Renderer/Renderer2D.h>
#include <Aurora/Renderer/Color.h>

#include "PlayerMovement.h"

class SandboxLayer : public Aurora::Layer
{

public:
    SandboxLayer();
    void OnUpdate(float dt) override;
    void OnRender() override;
    void OnEvent(
        Aurora::Event &event) override;

private:
    Aurora::Entity m_Player;
    Aurora::Camera2D m_Camera;
    std::shared_ptr<Aurora::Scene> m_Scene;
};