#pragma once

#include <Aurora/Core/Layer.h>
#include <Aurora/Scene/Entity.h>
#include <Aurora/Scene/Scene.h>
#include <Aurora/Scene/Components/SpriteComponent.h>
#include <Aurora/Scene/Components/TransformComponent.h>
#include <Aurora/Scene/Components/NameComponent.h>
#include <Aurora/Scene/Components/ScriptComponent.h>
#include <Aurora/Renderer/Camera2D.h>
#include <Aurora/Renderer/Renderer2D.h>

#include "PlayerMovement.h"

class SandboxLayer : public Aurora::Layer
{

public:
    SandboxLayer()
        : Layer("Sandbox")
    {
        m_Scene =
            std::make_shared<Aurora::Scene>();

        auto player =
            m_Scene->CreateEntity("Player");

        auto weapon =
            m_Scene->CreateEntity("Weapon");

        m_Scene->SetParent(weapon, player);

        auto &transform =
            player.GetComponent<
                Aurora::TransformComponent>();

        auto &script =
            player.AddComponent<Aurora::ScriptComponent>();

        script.Instance =
            new PlayerMovement();

        transform.Transform.Position =
            {200, 200};

        transform.Transform.Scale =
            {100, 200};

        player.AddComponent<
            Aurora::SpriteComponent>();
    }

    void OnUpdate(float dt) override;
    void OnRender() override;
    void OnEvent(
        Aurora::Event &event) override;

private:
    Aurora::Entity m_Player;
    Aurora::Camera2D m_Camera;
    std::shared_ptr<Aurora::Scene> m_Scene;
};