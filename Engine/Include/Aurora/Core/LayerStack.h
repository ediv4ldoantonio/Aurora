#pragma once

#include <vector>

#include "Aurora/Core/Layer.h"

namespace Aurora
{

    class LayerStack
    {

    public:
        LayerStack() = default;

        ~LayerStack();

        void PushLayer(
            Layer *layer);

        std::vector<Layer *>::iterator begin()
        {
            return m_Layers.begin();
        }

        std::vector<Layer *>::iterator end()
        {
            return m_Layers.end();
        }

    private:
        std::vector<Layer *> m_Layers;
    };

}