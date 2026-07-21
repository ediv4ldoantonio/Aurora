#include "Aurora/Renderer/Renderer2D.h"
#include "Aurora/Renderer/RendererAPI.h"

namespace Aurora
{

    RendererAPI *
        Renderer2D::s_Renderer = nullptr;

    void Renderer2D::Init(
        RendererAPI *renderer)
    {
        s_Renderer = renderer;

        s_Renderer->Init();
    }

    void Renderer2D::Shutdown()
    {
        s_Renderer = nullptr;
    }

    void Renderer2D::BeginFrame()
    {
        s_Renderer->BeginFrame();
    }

    void Renderer2D::EndFrame()
    {
        s_Renderer->EndFrame();
    }

    void Renderer2D::DrawRectangle(
        const Vector2 &position,
        const Vector2 &size)
    {
        s_Renderer->DrawRectangle(
            position,
            size);
    }

}