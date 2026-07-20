#include "Aurora/Core/LayerStack.h"

namespace Aurora
{

    LayerStack::~LayerStack()
    {

        for (auto layer : m_Layers)
        {
            layer->OnDetach();

            delete layer;
        }
    }

    void LayerStack::PushLayer(
        Layer *layer)
    {

        m_Layers.push_back(layer);

        layer->OnAttach();
    }

}