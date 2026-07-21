#include "Aurora/Core/LayerStack.h"

namespace Aurora
{

    LayerStack::~LayerStack()
    {
        for (auto it = m_Layers.rbegin();
             it != m_Layers.rend();
             ++it)
        {
            (*it)->OnDetach();
        }
    }

    void LayerStack::PushLayer(
        std::unique_ptr<Layer> layer)
    {
        layer->OnAttach();

        m_Layers.push_back(
            std::move(layer));
    }

    void LayerStack::OnEvent(
        Event &event)
    {

        for (auto it = m_Layers.rbegin();
             it != m_Layers.rend();
             ++it)
        {

            (*it)->OnEvent(event);

            if (event.Handled)
                break;
        }
    }

}