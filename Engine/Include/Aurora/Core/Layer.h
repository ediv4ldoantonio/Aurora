#pragma once

#include <string>

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

    protected:
        std::string m_Name;
    };

}