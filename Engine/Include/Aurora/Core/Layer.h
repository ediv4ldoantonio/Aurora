#pragma once

#include <string>
#include "Aurora/Events/Event.h"

namespace Aurora
{

    class Layer
    {

    public:
        explicit Layer(
            const std::string &name = "Layer")
            : m_Name(name)
        {
        }

        virtual ~Layer() = default;

        virtual void OnAttach()
        {
        }

        virtual void OnDetach()
        {
        }

        virtual void OnUpdate(
            float deltaTime)
        {
        }

        virtual void OnRender()
        {
        }

        virtual void OnEvent(
            Event &event)
        {
        }

    protected:
        std::string m_Name;
    };

}