#pragma once

#include <memory>

namespace Aurora
{

    class GraphicsContext
    {
    public:
        virtual ~GraphicsContext() = default;

        virtual void Init() = 0;

        virtual void BeginFrame() = 0;

        virtual void EndFrame() = 0;

        virtual void *GetNativeRenderer() const = 0;

        static std::unique_ptr<GraphicsContext> Create(void *nativeWindow);
    };

}