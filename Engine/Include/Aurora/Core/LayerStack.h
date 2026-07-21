#pragma once

#include <vector>
#include <memory>
#include "Aurora/Core/Layer.h"

namespace Aurora
{

    class LayerStack
    {

    public:
        LayerStack() = default;

        ~LayerStack();

        void PushLayer(std::unique_ptr<Layer>);

        std::vector<std::unique_ptr<Layer>>::iterator begin()
        {
            return m_Layers.begin();
        }

        std::vector<std::unique_ptr<Layer>>::iterator end()
        {
            return m_Layers.end();
        }

        void OnUpdate(
            float dt);

        void OnEvent(
            Event &event);

    private:
        std::vector<std::unique_ptr<Layer>> m_Layers;
    };

}
