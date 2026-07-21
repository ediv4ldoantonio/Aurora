#pragma once

#include <memory>

namespace Aurora
{

    class RendererAPI;

    class GraphicsContext
    {

    public:
        virtual ~GraphicsContext() = default;

        virtual void Init() = 0;

        virtual RendererAPI *
        GetRendererAPI() = 0;

        static std::unique_ptr<GraphicsContext> Create(void *nativeWindow);
    };

}